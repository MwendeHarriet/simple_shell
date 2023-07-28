#include "main.h"

/**
 * int_to_str -converts int to str
 * @num: int
 * @str: str
 */
void int_to_str(int num, char *str)
{
	char temp;
	int i;
	int len = 0;

	while (num > 0)
	{
		str[len++] = '0' + (num % 10);
		num /= 10;
	}

	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

/**
* handle_error -handle errors
 * @error_msg: error message
 * @command: command
 */
void handle_error(const char *error_msg, char *command)
{
	char error_statement[100];
	char exit_status_str[10];
	int exit_status = errno, len = 0, i;

	int_to_str(exit_status, exit_status_str);
	error_statement[len++] = '.';
	error_statement[len++] = '/';
	error_statement[len++] = 'h';
	error_statement[len++] = 's';
	error_statement[len++] = 'h';
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; exit_status_str[i] != '\0'; i++)
	{
		error_statement[len++] = exit_status_str[i];
	}
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; error_msg[i] != '\0'; i++)
	{
		error_statement[len++] = error_msg[i];
	}
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; command[i] != '\0'; i++)
	{
		error_statement[len++] = command[i];
	}
	error_statement[len++] = '\n';
	write(STDERR_FILENO, error_statement, len);
	exit(EXIT_FAILURE);
}

/**
 * execute_command -executes commands
 * @command: commmand
 * @args: args
 */
void execute_command(char *command, char **args)
{
	struct stat st;

	if (stat(command, &st) == 0)
	{
		if (access(command, X_OK) == 0)
		{
			if (execve(command, args, environ) == -1)
			{
				handle_error(strerror(errno), command);
			}
		}
		else
		{
			handle_error("permission denied", command);
		}
	}
	else
	{
		handle_error("no such file or directory", command);
	}
}

