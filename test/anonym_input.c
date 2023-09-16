#include "blezekshell.h"

/**
 * read_user_input - Reads stdin from an anonymous user
 *
 * @user_input: Pointer to the buffer that stores user input.
 * @buffer_size: Maximum number of characters to be read
 *
 * upon storing a read user input line of text, from the standard input
 * into the buffer, the function also ensures proper error handling and
 * removal of newline.
 */
void read_shell_input(char *shell_input, size_t buffer_size) 
{
	if (fgets(shell_input, buffer_size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			blezek_print("\n");
			exit(EXIT_SUCCESS);
		}

		else
		{
			blezek_print("Error upon reading anonymous user input.\n");
			exit(EXIT_FAILURE);
		}
	}
	shell_input[strcspn(shell_input, "\n")] = '\0';
}
