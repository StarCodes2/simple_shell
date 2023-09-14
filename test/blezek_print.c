#include "blezekshell.h"

/**
 * blezek_print - function that writes to StdOut
 *
 * @StdoutText: Pointer to a chatacter string.
 * also the text to be written to Stdout
 */
void blezek_print(const char *StdoutText) {
	write(STDOUT_FILENO, StdoutText, strlen(StdoutText));
}
