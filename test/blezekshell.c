#include "blezekshell.h"

/**
 * main - Entry point for the Blezek Shell
 *
 * Return: 0
 */
int main(void) {
	char shell_input[125];

	const char *path_dirs[] = {"/bin", "/usr/bin", NULL};;

	while (1)
	{
		shell_prompt_display();
		read_shell_input(shell_input, sizeof(shell_input));
		execute_shell_input(shell_input, path_dirs);
	}
	return (0);
}
