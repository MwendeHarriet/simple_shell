#include "main.h"
#include <stdlib.h>

/**
 *our_env -prints the current environment
 *@args: arguments
 *Return: nothing
 */
void our_env(void)
{
	extern char **environ;
	int i = 0;
	
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], our_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
