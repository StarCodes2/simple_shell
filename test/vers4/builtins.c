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
		if (arr[1])
		{
			int status = custom_atoi(arr[1]);
			_free(arr);
			exit(status);
		}
		else
		{
			_free(arr);
			exit(EXIT_SUCCESS);
		}
	}
	else if (_strcmp(arr[0], "env") == 0)
	{
		check = print_env();
		_free(arr);
	}
	else if (_strcmp(arr[0], "setenv") == 0)
	{
		if (arr[1] && arr[2])
		{
			if (set_env_variable(arr[1], arr[2]) == -1)
				print_err(arr[0], arr[1], "failwd to set environment variable");
			_free(arr);
		}
		else
			print_err(arr[0], "", "usagew: setenv VARIABLE VALUE");
		check = 0;
	}
	else
		check = 2;
	return (check);
}

/**
 * custom_atoi - custom atoi function to convert a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int custom_atoi(char *s)
{
	int result = 0;
	int i = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return result;
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

/**
 * set_env_variable - sets an environment variable
 * @variable: name of the variable
 * @value:value to assign to the variable
 *
 * Return: 0 on success, -1 on failure
 */
int set_env_varialw(char *variable, char *value)
{
	int overwrite = 1;
	if (setenv(variable, value, overwrite) == 0)
		return 0:
	else
		return -1;
}

/**
 * unset_env_variable - unsets an environment variable
 * @variable: name of the variable to unset
 *
 * Return: 0 on success, -1  on failure
 */
int unset_env_variable(char *variable)
{
	if (unsetenv(variable) == 0)
		return 0;
	else
		return -1;
}
