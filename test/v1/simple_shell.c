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
	char *line = NULL, **arr, **ar;
	int status;
	size_t size;
	pid_t child_pid;

	while (getline(&line, &size, stdin) != -1)
	{
		arr = line_to_av(line, " \n");
		ar = path_handler(arr);

		if (ar != NULL)
		{
			new_process(&child_pid);
			if (child_pid == 0)
				exec_cmd(ar, env);
			else
				wait(&status);
		}
		else
		{
			perror(argv[0]);
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
	char *line, **arr, **ar;
	int status;
	size_t size;
	pid_t child_pid;

	while (1)
	{
		print_prompt();
		getline(&line, &size, stdin);
		arr = line_to_av(line, " \n");
		if (strcmp(arr[0], "exit") == 0)
			break;
		ar = path_handler(arr);

		if (ar != NULL)
		{
			new_process(&child_pid);
			if (child_pid == 0)
				exec_cmd(ar, env);
			else
				wait(&status);
		}
		else
		{
			perror(argv[0]);
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
 */

void exec_cmd(char **arr, char **env)
{
	if (execve(arr[0], arr, env) == -1)
		perror("Error");
	exit(EXIT_FAILURE);
}
