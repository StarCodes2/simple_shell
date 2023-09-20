#include "main.h"

/**
 * cmd_check - checks if the commands should call a built in function and
 *		calls if it
 * @cmd: points to the command passed to the shell
 *
 * Return: 0 if a non-process ending command is passed
 *	1 if a process ending command is passed
 *	2 if no such commands are passed
 */

int cmd_check(char *cmd)
{
	int check;

	if (_strcmp(cmd, "exit") == 0)
		check = 1;
	else if (_strcmp(cmd, "env") == 0)
		check = print_env();
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
