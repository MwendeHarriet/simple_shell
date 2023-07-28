#include "main.h"

/**
 * execute_command - functions to execute the given command with arguments.
 * @command: The command being executed.
 * @args: Array of arguments for the command-line arguments.
 */
void execute_command(char *command, char **args)
{
	struct stat st;
	char error_statement[100];

	if (!command)
	{
		return;
	}
	if (stat(command, &st) == 0)
	{
		execve(command, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		int result = path(&command);

		if (result == 1)
		{
			our_strcpy(error_statement, command);
			our_strcpy(error_statement + our_strlen(command),
					" : No such file or directory\n");
			write(STDERR_FILENO, error_statement, our_strlen(error_statement));
			exit(EXIT_FAILURE);
		}
		else if (result == 2)
		{
			execve(command, args, environ);
		}
		else
		{
			our_strcpy(error_statement, command);
			our_strcpy(error_statement + our_strlen(command),
					" : No such file or directory\n");
			write(STDERR_FILENO, error_statement, our_strlen(error_statement));
			exit(EXIT_FAILURE);
		}
		free(command);
	}
}
