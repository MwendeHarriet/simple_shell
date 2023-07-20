#include "main.h"

/**
 * exit_status -exits the shell
 *@args: arguments
 *Return: 0
 */

int exit_status(char **args)
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
