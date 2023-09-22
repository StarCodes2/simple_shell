#include "main.h"

/**
 * cmd_check - checks if the commands should call a built in function and
 *		calls it if it's a built-in
 * @arr: array of strings allocated for a command and its arguments
 *
 * Return: 0 if a non-process ending command is passed
 *	1 if a process ending command is passed
 *	2 if no such commands are passed
 */

int cmd_check(char **arr)
{
	int check;
	if (_strcmp(arr[0], "exit") == 0)
	{
		_free(arr);
		exit(EXIT_SUCCESS);;
	}
	else if (_strcmp(arr[0], "env") == 0)
	{
		check = print_env();
		_free(arr);
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
