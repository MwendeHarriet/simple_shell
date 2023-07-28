#include "main.h"

/**
 * execute_command - functions to execute the given command with arguments.
 * @command: The command being executed.
 * @args: Array of arguments for the command-line arguments.
 */
void execute_command(char *command, char **args)
{
	char error_statement[100];
	struct stat st;
	
	if (!command)
	{
		return;
	}
	if (stat(command, &st) == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int result = path(&command);

		if (result == 1)
		{
			our_strcpy(error_statement, "./hsh: ");
			our_strcpy(error_statement + our_strlen("./hsh: "), command);
			our_strcpy(error_statement + our_strlen("./hsh: ") +
			our_strlen(command), ": No such file or directory\n");
			write(STDERR_FILENO, error_statement, our_strlen(error_statement));
			exit(EXIT_FAILURE);
		}
		else if (result == 2)
		{
			if (execve(command, args, environ) == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			our_strcpy(error_statement, "./hsh: ");
			our_strcpy(error_statement + our_strlen("./hsh: "), command);
			our_strcpy(error_statement + our_strlen("./hsh: ") +
			our_strlen(command), ": No such file or directory\n");
			write(STDERR_FILENO, error_statement, our_strlen(error_statement));
			exit(EXIT_FAILURE);
		}
		free(command);
	}
}
