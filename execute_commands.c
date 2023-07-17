#include "main.h"

/**
 * execute_command - functions to execute the given command with arguments.
 * @command: The command being executed.
 * @args: Array of arguments for the command-line arguments.
 */
void execute_command(char *command, char **args)
{
	char error_statement[100];

	execve(command, args, NULL);

	our_strcpy(error_statement, command);
	our_strcpy(error_statement + our_strlen(command),
			": command not found\n");

	write(STDERR_FILENO, error_statement, our_strlen(error_statement));
	exit(EXIT_FAILURE);
}
