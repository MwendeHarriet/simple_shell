#include "main.h"

/**
  *main - Entry point
  *Return: 0
  */
int main(void)
{
	char *setenv_args[] = {"setenv", "PATH", "/bin", NULL};

	our_setenv(setenv_args);
	read_execute_loop();

	return (EXIT_SUCCESS);
}
