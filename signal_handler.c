#include "main.h"

/**
 * sigint_handler - beginning of our code.
 * @sig: the exact signal.
 *
 */
void sigint_handler(int sig)
{
	char *global_buffer = NULL;

	(void)sig;
	if (global_buffer != NULL)
	{
		free(global_buffer);
		global_buffer = NULL;
	}
	our_putchar('\n');
	exit(130);
}

/**
 * flush_buffer -checks whether buffer contains spaces
 * or is empty
 * Return: nothing
 */
int flush_buffer(void)
{
	char *global_buffer = NULL;
	int i = 0;

	for (; global_buffer[i]; i++)
	{
		if (global_buffer[i] != ' ')
			return (0);
	}
	free(global_buffer);
	return (1);
}
