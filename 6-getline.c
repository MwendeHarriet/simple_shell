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
 * our_getline - our implementation of the LINUX getline which
 * reads a line from stdin.
 * Description: This function reads a line from stdin, storing it
 * in the buffer pointed to by lineptr. The buffer is dynamically
 * resized as needed by realloc and returns the length of the line read.
 * @lineptr: Pointer to line buffer.
 * @n: Pointer to size of buffer.
 * @stream: Pointer to stream to read from (not used in this implementation).
 * Return: On success, the length of the line read. If an error occurs
 * or end of file is reached, it returns -1.
 */
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t length = 0;
    char curr_char;
    int bytes_read;
    (void)stream;

    if (n == NULL || lineptr == NULL || *lineptr == NULL)
        return -1;

    *n = BUFFERSIZE;
    *lineptr = malloc(*n);
    if (*lineptr == NULL)
        return -1;

    fflush(stdout);
    (*lineptr)[0] = '\0';

    for (length = 0; ; length++)
    {
        if (our_strlen(*lineptr) + 1 == *n)
        {
            *n *= 2;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL)
                return -1;
        }

        bytes_read = read(STDIN_FILENO, &curr_char, 1);

        if (bytes_read == -1) 
        {
            free(*lineptr);
            return -1;
        }

        if (bytes_read == 0 && length == 0) 
        {
            free(*lineptr);
            return -1;
        }
        else if (bytes_read == 0)
        {
            bytes_read--;
            continue;
        }

        if (curr_char == '\n')
        {
            (*lineptr)[length] = curr_char;
            return length + 1;
        }

        (*lineptr)[length] = curr_char;
        (*lineptr)[length + 1] = '\0';
    }
}

