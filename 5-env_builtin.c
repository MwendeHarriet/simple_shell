#include "main.h"

/**
 *our_env -prints the current environment
 *@args: arguments
 *Return: nothing
 */
void our_env(void)
{
	int i = 0;
	
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], our_strlen(environ[i]));
		i++;
	}
}
