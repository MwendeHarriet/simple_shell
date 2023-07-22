#include "main.h"
#include <stdlib.h>

/**
 * our_strdup - Custom implementation of strdup function.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char *our_strdup(const char *s)
{
	size_t len = our_strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		our_strcpy(dup, s);
	}
	return (dup);
}

/**
 * our_strcat -attaches the contents of one string to the end
 * od another string including the terminating byte
 *@src: string to attach
 *@dest: string to attach to
 *Return: nothing
 */

void our_strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
