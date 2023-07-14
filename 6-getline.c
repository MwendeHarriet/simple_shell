#include "main.h"

/**
 * free_and_exit -frees the memory and exits with failure status
 * description: the function frees the memory pointed to
 * by line_buffer using free() and exits with the failure
 * status using exit()
 * @line_buffer: pointer to pointer to character
 */
void free_and_exit(char **line_buffer)
{
	free(*line_buffer);
	exit(EXIT_FAILURE);
}
/**
 *our_getline -our implementation of the LINUX getline which
 *reads a line from stdin
 *description: this function reads a line from a specific stream
 *storing it in buffer pointed to by lineptr, the buffer is dynamically
 *resized as needed by realloc and returns the length of the line read
 *@lineptr: pointer to line buffer
 *@n: pointer to size of buffer
 *@stream: pointer to stream to read from
 *Return: on success length of line read or if an error occurs or end of
 *file is reached it returns -1
 */
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t length = 0;

	char curr_chars;
	int bytes_read;
	(void)stream;
	if (n == NULL || lineptr == NULL || *lineptr == NULL)
		exit(EXIT_FAILURE);
	*n = BUFFERSIZE;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
		exit(EXIT_FAILURE);
	fflush(stdout);
	(*lineptr)[0] = '\0';
	for (length = 0; ; length++)
	{
		if (our_strlen(*lineptr) + 1 == *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				free_and_exit(lineptr);
		}
		bytes_read = read(STDIN_FILENO, &curr_chars, 1);
		if (bytes_read == 0 && length == 0)
			return (-1);
		else if (bytes_read == 0)
		{
			bytes_read--;
			continue;
		}
		if (curr_chars == '\n')
		{
			(*lineptr)[length] = curr_chars;
			return (length + 1);
		}
		(*lineptr)[length] = curr_chars;
		(*lineptr)[length + 1] = '\0';
	}
	free(*lineptr);
	exit(EXIT_FAILURE);
}
