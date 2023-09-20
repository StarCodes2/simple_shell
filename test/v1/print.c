#include "main.h"

/**
 * print_prompt - print the prompt for the shell interactive mode
 */

void print_prompt(void)
{
	int len;
	char *s = "#cisfun$ ";

	len = _strlen(s);
	write(1, s, len);
}

/**
 * print_buf - print the content of a string/array
 * @buffer: points to the buffer, string or array
 * @index: points to a variable that contains the characters to be printed
 */

void print_buf(char *buffer, int *index)
{
	if (*index > 0)
		write(1, buffer, *index);
	*index = 0;
}
