#include "main.h"

/**
 * void free_and_exit -frees the memory and exits the
 * programme with a failure status
 * description: the function frees the memory pointed to
 * by line_buffer using free() and exits with the failure
 * status using exit()
 */
void free_and_exit(char **line_buffer)
{
	free(*line_buffer);
	exit(EXIT_FAILURE);

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
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t length = 0;

	char curr_characters;
	int read_result;
	(void)stream;
	
	if (n ==NULL || lineptr == NULL || *lineptr ==NULL)
	       exit(EXIT_FAILURE);
	
	*n = BUFFERSIZE;	
