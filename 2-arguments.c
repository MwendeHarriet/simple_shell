#include "main.h"
#include <string.h>

/**
 * parse_arguments - Parses command line arguments
 * @input: The input string containing the command and arguments
 * @args: Array to store the parsed arguments
 *
 * Return: The number of arguments parsed
 */
int parse_arguments(char *input, char **args)
{
	int count = 0;
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		args[count] = our_strdup(token);
		count++;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;

	return (count);
}
