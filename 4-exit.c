#include "main.h"

/**
 * exit_shell - Handles the exit command
 * @args: Array of command-line arguments
 * @buffer: the buffer
 * @av: arguments
 * @lines: arguments
 * Return: The exit status to be returned
 */
int exit_shell(char **args, void *buffer, void *av, void *lines)
{
	int exit_status;
	(void)buffer;
	(void)av;
	(void)lines;
	if (our_strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			return (0);

		exit_status = our_atoi(args[1]);

		if (exit_status < 0 || exit_status > 255)
		{
			our_printf("./hsh: exit: %d: numeric argument required\n", exit_status);
			return (2);
		}

		return (exit_status);
	}
	return (0);
}

