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
	write(STDOUT_FILENO, "\n", 1);
	exit(130);
}
