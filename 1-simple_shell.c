#include "main.h"


/**
  *display_prompt -  Functions to allow user to see prompt
  */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun:)", 10);
}

#include "main.h"

/**
 * execute_input - Functions to execute commands.
 * @input: The command to be executed.
 *
 * Return: The result after execution of the command.
 */
void execute_input(char *input)
{
	int argc = 0;
	char *argv[MAX_ARGS + 1];
	char *token = strtok(input, " \t\n");

	while (token != NULL && argc < MAX_ARGS)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;

	if (argc == 0)
	{
		return;
	}
	execute_command_or_process(argc, argv);
}

/**
 * execute_command_or_process - Execute the appropriate command or process.
 * @argc: Number of arguments in the command.
 * @argv: Array of arguments in the command.
 */
void execute_command_or_process(int argc, char *argv[])
{
	pid_t pid;

	if (our_strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
		{
			int exit_shell = our_atoi(argv[1]);

			exit(exit_shell);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (our_strcmp(argv[0], "env") == 0)
	{
		our_env();
	}
	else
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execute_command(argv[0], argv);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
}

/**
  *read_execute_loop - read a line from the standard input
  *Return: pointer that points to a str with the line content
  */
void read_execute_loop(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t buffersize;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		buffersize = getline(&input, &bufsize, stdin);
		if (buffersize == -1)
		{
			if (feof(stdin))
			{
				free(input);
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(input);
				perror("Error while reading the line from stdin");
				exit(EXIT_FAILURE);
			}
		}
		if (buffersize > 0 && input[buffersize - 1] == '\n')
		{
			input[buffersize - 1] = '\0';
		}
		if (our_strcmp(input, "") == 0)
		{
			continue;
		}

		execute_input(input);

	}

}
