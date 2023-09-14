#include "blezekshell.h"

/**
 * main - Entry point for the Blezek Shell
 *
 * Return: Always returns 0
 */
int main(void) {
	char shell_input[135];

	for (;;)
	{
		shell_prompt_display();
		read_user_input(user_input, sizeof(user_input));
		execute_shell_input(shell_input);
	}
	return (0);
}
