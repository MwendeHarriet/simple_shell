#include "main.h"

/**
 * our_getline -entry point
 * @input: input
 * @bufsize: buffsize
 * @stream: stream
 */

int our_getline(char **input, size_t *bufsize, FILE *stream) {
    int ch;
    char *temp;
    size_t len = 0;
    size_t capacity = 16;

    char *buffer = (char *)malloc(capacity * sizeof(char));
    if (!buffer) {

        write(STDERR_FILENO, "Memory allocation failed.\n", 26);
        return -1;
    }

    while ((ch = fgetc(stream)) != EOF && ch != '\n') {
       
        if (len == capacity - 1) {
            capacity *= 2;
       		temp = (char *)realloc(buffer, capacity * sizeof(char));
            if (!temp) {
               
                free(buffer);
                write(STDERR_FILENO, "Memory allocation failed during resize.\n", 40);
                return -1;
            }
            buffer = temp;
        }

        buffer[len++] = ch;
    }


    buffer[len] = '\0';

    *input = buffer;
    *bufsize = capacity;
	
    return len;
}

