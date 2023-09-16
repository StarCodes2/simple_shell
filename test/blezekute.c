#include "blezekshell.h"

/**
 * execute_shell_input - function that executes user input
 *
 * @shell_input: User input string
 */
void execute_shell_input(const char *shell_input)
{
	char *token;
	char *args[64];
	int arg_count = 0;

	token = strtok((char*)shell_input, " ");
	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			blezek_print("Error executing the command.\n");
		}
	}
}
