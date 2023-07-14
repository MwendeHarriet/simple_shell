#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>

/*used in our_getline*/
#define BUFFERSIZE 1024

/*our_putchar*/
int our_putchar(char c);

/*our_getline*/
void free_and_exit(char **line_buffer);
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream);

#endif
