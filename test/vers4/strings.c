#include "main.h"

/**
 * _strcat - adds the string in src to the one in dest
 * @dest: point's to the first string
 * @src: point's to the second string
 *
 * Return: a pointer to the string in dest
 */

char *_strcat(char *dest, char *src)
{
	int index, index2 = 0, len = 0;

	while (dest[len])
		len++;

	for (index = len; src[index2] != '\0'; index++)
		dest[index] = src[index2++];
	dest[index] = '\0';

	return (dest);
}

/**
 * _strlen - counts the number of characters in a string
 * @s: point's to the string
 *
 * Return: the result
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - copy's a string from one memory location to another
 * @dest: point's to the location where the string is copied to
 * @src: point's to the location where the string is copied from
 *
 * Return: a pointer to the new string
 */

char *_strcpy(char *dest, char *src)
{
	int index;

	for (index = 0; src[index]; index++)
		dest[index] = src[index];
	dest[index] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: points to the first string
 * @s2: pojnts to the second string
 *
 * Return: a negative value if s1 < s2
 *	zero if s1 = s2
 *	and a possitive value if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	int index = 0;

	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;

	return (s1[index] - s2[index]);
}
