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
void read_user_input(char *user_input, size_t buffer_size) 
{
	if (fgets(user_input, buffer_size, stdin) == NULL)
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
	user_input[strcspn(user_input, "\n")] = '\0';
}
