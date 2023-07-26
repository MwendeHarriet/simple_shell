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
		int exit_val = our_atoi(args[1]);

		exit(exit_val);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
