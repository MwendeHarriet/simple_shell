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

/**
  *tokenise_input -this function takes the command line arguments,
  *splits them into separate tokens and stores the command token and
  *argument tokens in the provided arrays
  *@argc: argument counter
  *@argv: argument vector,array of command argument strings
  *@command: pointer to command token
  *@args: array to argument tokens
  *Return: nothing
  */
void tokenise_input(int argc, char *argv[], char **command, char **args)
{
	int args_index = 0;

	int i;
	*command = argv[1];

	for (i = 2; i < argc; i++)
	{
		args[args_index] = argv[i];
		args_index++;
	}

	args[args_index] = NULL;
}
