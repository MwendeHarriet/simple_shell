#include "main.h"
#include <string.h>

/**
 *execute_ccommand - Execute a command in a child process
 *@command: The command to execute
 *This function forks a child process and executes the specified command.
 * It tokenizes the command string and uses execvp to execute the command
 * in the child process.
 */
void execute_ccommand(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		char *args[MAX_ARGS];
		char *token;
		int arg_count = 0;

		token = strtok(command, " ");
		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execve(args[0], args, NULL);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		write(STDERR_FILENO, "fork failed\n", 12);
		return;
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
/**
 *process_input - Process user input and execute commands
 *
 *This function reads user input from stdin, executes the specified commands,
 * and continues reading until an EOF is encountered.
 */

void process_input(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
		write(STDOUT_FILENO, ":) ", 3);
		characters = getline(&command, &bufsize, stdin);
		if (characters == -1)
			break;
		command[characters - 1] = '\0';

		if (strcmp(command, "") == 0)
			continue;

		execute_ccommand(command);
	}

	free(command);
}
/**
 *path_main - gets the PATH environment variable
 * and processes user input
 *Return: EXIT_SUCCESS on success, or EXIT_FAILURE
 *if PATH environment variable is not available
 *
 */

int path_main(void)
{
	char *path = NULL;

	path = getenv("PATH");
	if (path == NULL)
	{
		write(STDERR_FILENO, "Failed to retrieve PATH environment variable\n", 45);
		return (EXIT_FAILURE);
	}

	process_input();

	return (EXIT_SUCCESS);
}

