#include "main.h"

/**
 * child_process -creates the child process of the shell
 * @av: arguments
 * @p: path
 * @shell: argv[0]
 * @exit_status: Value of exit status
 * Return: int
 */
int child_process(char **av, char *shell, char *p, int *exit_status)
{
	int shell_status;
	pid_t pid;
	int i = 1;

	pid = fork();
	if (pid == 0)
	{
		if (execve(p, av, environ) == -1)
			perror(shell);
	}
	else if (pid == -1)
		return (0);

	wait(&shell_status);
	if (WIFEXITED(shell_status))
	{
		*exit_status = WEXITSTATUS(shell_status);
		if (*exit_status != 0)
		i = 1;
	}
	else
	{
		i = 0;
	}
	if (our_strcmp(p, av[0]))
		free(p);
	return (i);
}
