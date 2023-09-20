#include "main.h"

/**
 * print_err - prints an error message
 * @p_name: points to the program file path
 * @cmd: points to the cmd string
 * @msg: holds message to be added to the error
 */

void print_err(char *p_name, char *cmd, char *msg)
{
	print(p_name);
	print(": ");
	print_num(errno);
	print(": ");
	print(cmd);
	print(": ");
	print(msg);
	_putchar('\n');
}
