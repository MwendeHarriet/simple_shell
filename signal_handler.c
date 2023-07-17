#include "main.h"

/**
 * sigint_handler - beginning of our code.
 * @sig: the exact signal.
 * @buffer: Pointer to the buffer that needs to be freed.
 */
void sigint_handler(int sig, char *buffer)
{
	(void) sig;
	free(buffer);
	our_putchar('\n');
	exit(130);
}
