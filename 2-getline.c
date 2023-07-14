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
 *description: 
 *@lineptr: pointer to line buffer
 *@n: pointer to size of buffer
 *@stream: pointer to stream to read from
