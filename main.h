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

#define MAX_ARGS 100

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
void read_execute_loop(void);

/*our_strcmp*/
int our_strcmp(const char *str1, const char *str2);

/*our_env*/
void our_env(void);

/*arguments*/
int parse_arguments(char *input, char **args);

/*signal handler*/
void sigint_handler(int sig, char *buffer);

/*execute commands*/
void execute_command(char *command, char **args);

/*our_strcpy*/
void our_strcpy(char *dest, const char *src);


/*exit_status*/
int exit_status(char **args);

/*our_setenv*/
int our_setenv(char **args);

/*our_unsetenv*/
int our_unsetenv(char **args);

/*exit*/
int exit_shell(char **args);

/*our_atoi*/
int our_atoi(const char *str);

void execute_ccommand(char *command);
/*path.c*/
int path(char **av);
int path_free(char **path, int num, int return_value);
void put_paths(char **path, const int num, char *tok);
/*custom functions*/
char *our_strdup(const char *s);
void our_strcat(char *dest, const char *src);
int our_snprintf(char *str, size_t size, const char *format, ...);
const char *our_getenv(const char *name);
int our_strncmp(const char *str1, const char *str2, size_t n);
int shell_main(void);
int tokenize(char *s, char c);
#endif
