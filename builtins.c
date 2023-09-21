#include "main.h"

/**
 * cmd_check - checks if the commands should call a built in function and
 *		calls if it
 * @cmd: points to the command passed to the shell
 * @arr: array of strings allocated for command
 *
 * Return: 0 if a non-process ending command is passed
 *	1 if a process ending command is passed
 *	2 if no such commands are passed
 */

int cmd_check(char *cmd, char **arr)
{
	int check;

	if (_strcmp(cmd, "exit") == 0)
	{
		_free(arr);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(cmd, "env") == 0)
	{
		check = print_env();
		_free(arr);
		return (1);
	}
	else
		check = 2;
	return (check);
}

/**
 * print_env - prints the environment variables
 *
 * Return: 0 always
 */

int print_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		print(environ[index]);
		print("\n");
	}

	return (0);
}
