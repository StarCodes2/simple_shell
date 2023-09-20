#include "main.h"

/**
 * _free - free a memory if its allocated
 * @s: points to the memory
 */

void _free(void *s)
{
	if (s)
		free(s);
}
