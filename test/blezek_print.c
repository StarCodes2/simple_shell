#include "blezekshell.h"

/**
 * blezek_print - function that writes to StdOut
 *
 * @stdouttext: Pointer to a chatacter string.
 * also the text to be written to Stdout
 */
void blezek_print(const char *stdouttext) {
	write(STDOUT_FILENO, stdouttext, strlen(stdouttext));
}
