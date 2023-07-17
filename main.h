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

extern char **environ;

/*used in our_getline*/
#define BUFFERSIZE 1024

/*our_putchar*/
int our_putchar(char c);

/*our_getline*/
void free_and_exit(char **line_buffer);
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream);

/*our_strlen*/
size_t our_strlen(const char *str);

/*simple_shell*/
void execute_input(char *input);
void display_prompt(void);
int main(void);
char *read_line(void);

/*our_strcmp*/
int our_strcmp(const char *str1, const char *str2);

/*our_env*/
void our_env(void);

/*arguments*/
int parse_arguments(char *input, char **args);

/*signal handler*/
void sigint_handler(int sig);

#endif
