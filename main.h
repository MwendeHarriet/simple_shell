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
#include <string.h>
#include <stdbool.h>

#define MAX_ARGS 100

extern char **environ;

extern char *global_buffer;

/*used in our_getline*/
#define BUFFERSIZE 1024

/*our_putchar*/
int our_putchar(char c);

/*our_getline*/


/*our_strlen*/
size_t our_strlen(const char *str);

/*simple_shell*/
void execute_input(char *input);
void display_prompt(void);
void read_execute_loop(void);
void execute_command_or_process(int argc, char *argv[]);

/*child_process*/
int child_process(char **av, char *shell, char *p, int *exit_status);

/*our_strcmp*/
int our_strcmp(const char *str1, const char *str2);

/*our_env*/
void our_env(void);

/*arguments*/
int parse_arguments(char *input, char **args);
char *get_arguments(char **buffer, char **av, char *p);

/*signal handler*/
void sigint_handler(int sig);

/*execute commands*/
void execute_command(char *command, char **args);

/*our_strcpy*/
void our_strcpy(char *dest, const char *src);

/*our_setenv*/
int our_setenv(char **args, void *env, const char *prog_name);

/*our_unsetenv*/
int our_unsetenv(char **args, void *env, const char *prog_name);

/*exit*/
int exit_shell(char **args, void *buffer, void *av, void *lines);

/*our_atoi*/
int our_atoi(const char *str);

/*path.c*/

char *find_command_path(char *command, char *path);
void process_input(void);
int path_main(void);

/*our_strdup*/
char *our_strdup(const char *s);

int path(char **av);
int tokenize(char *s, char c);
int path_free(char **path, int num, int return_value);
void put_paths(char **path, const int num, char *tok);

/*custom functions*/
/*our_strdup*/
char *our_strdup(const char *s);


/*our_strcat*/
void our_strcat(char *dest, const char *src);

/*write_strings*/
int write_strings(char *str);

/*write_numbers*/
int write_numbers(int nums);

/*main*/
int main(void);

/*check_enter*/
int check_enter(char **buffer);

/*exee_error*/
void exe_error(char **av, char **buffer, char *hsh);

/*check_input_return*/
void check_input_return(int input, int *running, char **buffer);

/*check_input*/
int check_input(char **buffer, char *av[]);

/*our_strchr*/
char *our_strchr(const char *str, int c);

/*our_printf*/
int our_printf(const char *format, ...);

/*our_strncmp*/
int our_strncmp(const char *s1, const char *s2, size_t n);

/*get_variable*/
void get_variables(char **tokens, int *exit_status);

/*tokenise_input*/
char **tokenise(char *buffer, char delimiter);

/*our_strsep*/
char *our_strsep(char **stringp, const char *delim);

/*flush_buffer*/
int flush_buffer(void);

/*free_input*/
void free_input(char *input);


int our_snprintf(char *str, size_t size, const char *format, ...);
const char *our_getenv(const char *name);
int shell_main(void);

#endif
