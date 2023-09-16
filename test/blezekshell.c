#include "blezekshell.h"

/**
 * main - Entry point for the Blezek Shell
 *
 * Return: 0
 */
int main(void) {
	char shell_input[125];

	while (1)
	{
		shell_prompt_display();
		read_shell_input(shell_input, sizeof(shell_input));
		execute_shell_input(shell_input);
	}
	return (0);
}
