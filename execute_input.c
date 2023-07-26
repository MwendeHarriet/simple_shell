#include "main.h"

/**
 * tokenise_input - tokenise a string using a delimiter as base
 * @buffer: string to tokenise
 * @delimiter: delimiter character
 * Return:array of tokens
 */
char **tokenise_input(char *buffer, char delimiter)
{
	char *token;
	char *copy_buffer = our_strdup(buffer);

	char **tokenise_input = NULL, *pbuffer = copy_buffer;

	size_t count = 0;

	while ((token = our_strsep(&pbuffer, &delimiter)) != NULL)

	{
		tokenise_input = realloc(tokenise_input, (count + 1) * sizeof(char *));
		tokenise_input[count] = our_strdup(token);
		count++;
	}
	tokenise_input = realloc(tokenise_input, (count + 1) * sizeof(char *));
	tokenise_input[count] = NULL;
	free(copy_buffer);
	return (tokenise_input);
}

/**
 * free_tokens - free memory allocated for tokens
 * @tokenise_input: tokens array to free
 */
void free_tokens(char **tokenise_input)
{
	int i;

	for (i = 0; tokenise_input[i] != NULL; i++)
	{
		free(tokenise_input[i]);
	}
	free(tokenise_input);
}

/**
* check_input -checks input from the command line
* @buffer: has the user input
* @av: string array with input
* Return: 0 on success
*/
int check_input(char **buffer, char *av[])
{
	size_t length = 0;

	int exit_status = 0;

	ssize_t read;
	char *end_command, **tokens;
	int i;

	read = our_getline(buffer, &length, stdin);
	if (read == -1 || (*buffer)[read - 1] != 10)
	{
		return (-1);
	}
	(*buffer)[read - 1] = '\0';
	end_command = our_strchr(*buffer, '#');
	if (end_command != NULL && end_command[-1] == ' ')
	{
		*end_command = '\0';
	}
	av[0] = (*buffer);
	av[1] = NULL;
	if (read == 1)
		return (1);
	if (!isatty(STDIN_FILENO))
	{
		return (2);
	}
	tokens = tokenise_input(*buffer, ' ');
	if (our_strcmp(tokens[0], "echo") == 0)
	{
		get_variables(tokens, &exit_status);
		for (i = 1; tokens[i] != NULL; i++)
		{
			our_printf("%s", tokens[i]);
		}
		our_printf("\n");
	}
	free_tokens(tokens);
	return (0);
}
