#include "main.h"

/**
 *our_setenv -this function mimics the setenv builtin
 *@args: an array of command line arguments
 *@env: environment
 *@prog_name: shell name
 *Return: on success 0 or on failure -1
 */
int our_setenv(char **args, void *env, const char *prog_name)
{
	const char *usage_msg = "Usage: setenv VARIABLE VALUE\n";

	const char *error_msg = "Error: unable to set environment variable.\n";

	int overwrite = 1;

	(void)env;
	(void)prog_name;
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, usage_msg, our_strlen(usage_msg));
		return (-1);
	}
	if (setenv(args[1], args[2], overwrite) != 0)
	{
		write(STDERR_FILENO, error_msg, our_strlen(error_msg));
		return (-1);
	}
	return (0);
}

/**
 *our_unsetenv -this function mimics the unsetenv builtin
 *@args: an array of command line arguments
 *@env: environment
 *@prog_name: shell name
 *Return: on success 0 or on failure -1
 */
int our_unsetenv(char **args, void *env, const char *prog_name)
{
	const char *usage_msg = "Usage: unsetenv VARIABLE VALUE\n";

	const char *error_msg = "Error: unable to unset environment variable.\n";

	(void)env;
	(void)prog_name;
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, usage_msg, our_strlen(usage_msg));
		return (-1);
	}
	if (unsetenv(args[1]) != 0)
	{
		write(STDERR_FILENO, error_msg, our_strlen(error_msg));
		return (-1);
	}
	return (0);
}
