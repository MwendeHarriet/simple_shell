#include "main.h"

/**
 * check_input_return - checks input status returned by
* check input
* @input: input
* @running: running
* @buffer: buffer
* Return: 0 on success
*/
void check_input_return(int input, int *running, char **buffer)
{
	if (input == -1)
	{
		*running = 0;
		free(*buffer);
	}
	else if (input == 2)
		*running = 1;
}

/**
* exe_error - Entry point
* @av: args
* @buffer: input
* @hsh: shell name
* Return: 0 on success
*/
void exe_error(char **av, char **buffer, char *hsh)
{
	if (execve(av[0], av, environ) == -1)
		perror(hsh);
	free(*buffer);

}

/**
* check_enter - checks if user entered
* @buffer: buffer
* Return: 1 on success
*/
int check_enter(char **buffer)
{
	if (*buffer[0] == '\0')
	{
		free(*buffer);
		return (1);
	}
	return (0);
}

/**
 * get_arguments -gets arguments
 * @buffer: buffer
 * @av: first argument
 * @p: path
 * Return: path
 */
char *get_arguments(char **buffer, char **av, char *p)
{
	if (our_strcmp(*buffer, av[0]))
	{
		p = our_strdup(av[0]);
		free(av[0]);
		av[0] = our_strdup(*buffer);
	}
	else
		p = av[0];
	return (p);
}

/**
* main - Entry point
* @argc: argument counter
* @argv: argument
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *av[20] = {NULL}, *p;
	int num = 0, running = 1, input = 0, lines = 0;
	char *buffer = NULL;
	int exit_status = 0;
	
	signal(SIGINT, sigint_handler);
	(void) argc;
	do {
		if (isatty(STDIN_FILENO))
			our_printf("#cisfun$");
		lines++;
		input = check_input(&buffer, av);
		check_input_return(input, &running, &buffer);
		if (input != -1)
		{
			if (check_enter(&buffer) || flush_buffer())
			{
				continue;
			}
			if (our_strcmp(buffer, "env") == 0)
			{
				our_env();
				free(buffer);
				continue;
			}
			if (our_strncmp("echo ", buffer, 5) == 0)
			{
				our_printf("%s\n", buffer + 5);
				free(buffer);
				continue;
			}
			num = parse_arguments(buffer, av);
			if (our_setenv(&buffer, av, argv[0]) || our_unsetenv(&buffer, av, argv[0]))
			continue;
			if (our_strncmp(av[0], "exit", 4) == 0)
			{
				exit_shell(av, buffer, av, &lines);
				continue;
			}
			else if (!num)
			{
				our_printf("./hsh: %d: %s: not found\n", lines, av[0]);
				free(buffer);
				exit_status = 127;
			}
			else
			{
				if (num == 2)
					p = get_arguments(&buffer, av, p);
				else
					p = av[0];
				running = child_process(av, argv[0], p, &exit_status);
				free(buffer);
				if (num == 2)
				free(av[0]);
				check_input_return(input, &running, &buffer);
			}
		}
	} while (running);
	return (exit_status);
}
