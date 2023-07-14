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
  *@input: The command to be executed
  *@argc: argument counter
  *Return: the result after execution of command
  */
void execute_input(char *input, int argc)
{
	char *argv[] = {input, NULL};

	int val = execve(input, argv, NULL);

	if (val == -1)
	{
		char *error_statement = ("No such file or directory\n");

		write(STDOUT_FILENO, error_statement, 30);
		exit(1);
	}
}
/**
<<<<<<< HEAD
  *read_line - read a line from the standard input
  *
  *Return: pointer that points to a str with the line content
  */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
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
	return (line);
}

/**
  *main - Entry point
  *@argc: The number of command-line arguments
  *@argv: Array of command-line arguments
  *Return: 0
  */
int main(int argc, char *argv[])
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
			execute_input(input, argc);
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
=======
 */
>>>>>>> 92048228ff9d8b706d056798f7ccd828a62fe5e1
