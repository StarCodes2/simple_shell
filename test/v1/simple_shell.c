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

int main(int argc, char **argv, char **env)
{
	char *s, **arr;
	int status, exit = 0, check_arg = 0;
	size_t size;
	pid_t child_pid;

	if (argc > 1)
		check_arg = 1;

	while (!exit)
	{
		if (check_arg)
		{
			arr = argv;
			arr++;
		}
		else
		{
			printf("#cisfun$ ");
			getline(&s, &size, stdin);
			arr = line_to_av(s, " \n");
		}

		new_process(&child_pid);
		if (child_pid == 0)
			exec_cmd(arr, env);
		else
			wait(&status);

		if (!check_arg)
			free(arr);
		else
			check_arg = 0;
	}
	return (0);
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
