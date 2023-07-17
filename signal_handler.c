#include "main.h"

/**
 * sigint_handler - beginning of our code.
 * @sig: the exact signal.
 */
void sigint_handler(int sig)
{
	(void) sig;
	free(buffer);
	_putchar('\n');
	exit(130);
}
