#include "main.h"

/**
 * exit_shell -exits the shell
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
