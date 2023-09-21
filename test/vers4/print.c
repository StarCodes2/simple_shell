#include "main.h"

/**
 * print - prints a string to standard output
 * @s: points to a string
 */

void print(char *s)
{
	int len;

	len = _strlen(s);
	write(1, s, len);
}

/**
 * print_num - prints num to standard output
 * @num: holds number
 */

void print_num(int num)
{
	if (num < 0)
	{
		num *= -1;
		_putchar('-');
	}

	if (num > 9)
		print_num(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * _putchar - prints a char to standard output
 * @c: holds the cha
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	int count;

	count = write(1, &c, 1);

	return (count);
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
