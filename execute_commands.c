#include "main.h"

/**
 * execute_command - functions to execute the given command with arguments.
 * @command: The command being executed.
 * @args: Array of arguments for the command-line arguments.
 */
void execute_command(char *command, char **args)
{
	struct stat st;

	if (!command)
		return;

	if (stat(command, &st) == 0)
	{
		if (access(command, X_OK) == 0)
		{
			if (execve(command, args, environ) == -1)
			{
				write(STDERR_FILENO, "./hsh: ", 7);
				write(STDERR_FILENO, command, strlen(command));
				write(STDERR_FILENO, ": ", 2);
				perror(NULL);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			write(STDERR_FILENO, "./hsh: ", 7);
			write(STDERR_FILENO, command, strlen(command));
			write(STDERR_FILENO, ": permission denied\n", 20);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(STDERR_FILENO, "./hsh: ", 7);
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, ": no such file or directory\n", 28);
		exit(EXIT_FAILURE);
	}
}
