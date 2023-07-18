#include "main.h"
/**
  *display_prompt -  Functions to allow user to see prompt
  */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun:)", 10);
}


/**
  *execute_input - functions to execute commands
  *@input: The command to be executed.
  *Return: the result after execution of command
  */
void execute_input(char *input)
{
	int val;
	char **argv = malloc(2 * sizeof(char *));

	if (argv == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(1);
	}
	free(argv);
	argv[0] = input;
	argv[1] = NULL;

	val = execve(input, argv, NULL);

	if (val == -1)
	{
		char *error_statement = ("No such file or directory\n");

		write(STDOUT_FILENO, error_statement, 30);
		exit(1);
	}
	free(argv);
}

/**
  *read_line - read a line from the standard input
  *
  *Return: pointer that points to a str with the line content
  */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (our_getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (line);
}

/**
  *main - Entry point
  *Return: 0
  */
int main(void)
{
	ssize_t buffersize;
	char *input = NULL;
	size_t n = 0;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		buffersize = getline(&input, &n, stdin);
		if (buffersize == -1)
		{
			write(STDERR_FILENO, "\n", 1);
			break;
		}
		input[buffersize - 1] = '\0';
		if (our_strcmp(input, "") == 0)
			continue;

		pid = fork();

		if (pid < 0)
		{
			perror("Error: Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			execute_input(input);
		}
		else
		{
			wait(NULL);
		}
		free(input);
		input = NULL;
		n = 0;
	}
	return (0);
}
