#include "main.h"

/**
 * main - Super simple shell that can run commands with their full path,
 * without any argument.
 * @argc: contains the number of arguments passed to main
 * @argv: contains an array of pointers to thw string arguments
 * @env: contain's an array of pointers to environment variables
 *
 * Return: 0 on success
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	if (isatty(STDIN_FILENO))
		interactive_mode(argv, env);
	else
		non_interactive_mode(argv, env);

	return (0);
}

/**
 * non_interactive_mode - Handle shell commands in non_interactive mode
 * @argv: points to an array of string arguments
 * @env: points to a pointer that points a string of environment variables
 */

void non_interactive_mode(char **argv, char **env)
{
	char *line = NULL, **arr = NULL, **ar = NULL;
	int status, c_check;
	size_t size;
	pid_t child_pid;

	while (getline(&line, &size, stdin) != -1)
	{
		arr = line_to_av(line, " \n");
		if (arr == NULL)
			continue;

		c_check = cmd_check(arr[0], arr);
		if (c_check == 0)
			continue;
		else if (c_check == 1)
			break;

		ar = path_handler(arr);
		if (ar != NULL)
		{
			new_process(&child_pid);
			if (child_pid == 0)
				exec_cmd(ar, env, arr[0]);
			else
				wait(&status);
		}
		else
		{
			print_err(argv[0], arr[0], "not found");
		}
		if (ar)
			_free(ar[0]);
		_free(arr);
	}
	_free(line);
}

/**
 * interactive_mode - Handle shell commands in interactive mode
 * @argv: points to an array of string arguments
 * @env: points to a pointer that points a string of environment variables
 */

void interactive_mode(char **argv, char **env)
{
	char *line = NULL, **arr = NULL, **ar = NULL;
	int status, c_check, l_check;
	size_t size;
	pid_t child_pid;

	while (1)
	{
		print("($) ");
		l_check = getline(&line, &size, stdin);
		if (l_check == -1)
			continue;
		arr = line_to_av(line, " \n");
		if (arr == NULL)
			continue;

		c_check = cmd_check(arr[0], arr);
		if (c_check == 0)
			continue;
		else if (c_check == 1)
			break;

		ar = path_handler(arr);
		if (ar != NULL)
		{
			new_process(&child_pid);
			if (child_pid == 0)
				exec_cmd(ar, env, arr[0]);
			else
				wait(&status);
		}
		else
		{
			print_err(argv[0], arr[0], "not found");
		}
		if (ar != NULL)
			_free(ar[0]);
		_free(arr);
	}
	_free(line);
}

/**
 * new_process - creates a new process
 * @pid: points to a process id
 */

void new_process(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("Error:");
		exit(1);
	}
}

/**
 * exec_cmd - executes a shell command
 * @arr: points to the command and its arguments
 * @env: points to the environment variables
 * @cmd: points to the command string
 */

void exec_cmd(char **arr, char **env, char *cmd)
{
	if (execve(arr[0], arr, env) == -1)
		perror(cmd);
	exit(EXIT_FAILURE);
}
