#include "main.h"

/**
 * execute_command - functions to execute the given command with arguments.
 * @command: The command being executed.
 * @args: Array of arguments for the command-line arguments.
 */
void execute_command(char *command, char **args)
{
	const char *path = our_getenv("PATH");
	char *full_path = NULL;
	char error_statement[100];

	if (!command)
	{
		return;
	}
	if (path)
		full_path = find_command_path(command, path);

	if (full_path)
	{
		execve(full_path, args, NULL);
		free(full_path);
	}
	our_strcpy(error_statement, command);
	our_strcpy(error_statement + our_strlen(command),
			": command not found\n");

	write(STDERR_FILENO, error_statement, our_strlen(error_statement));
	exit(EXIT_FAILURE);
}
