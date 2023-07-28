#include "main.h"

/**
 * exit_shell - Handles the exit command
 * @args: Array of command-line arguments
 * @buffer: the buffer
 * @av: arguments
 * @lines: arguments
 * Return: The exit status to be returned
 */
int exit_shell(char **args)
{
	if (args[1])
	{
		return (our_atoi(args[1]));
	}
	else
	{
		return (0);
	}
}
