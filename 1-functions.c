#include "main.h"

/**
 *our_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int our_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * our_strlen -calculates the length of a string
 * @str: input string
 *
 * Return: length of the string
 */
size_t our_strlen(const char *str)
{
	const char *pointer = str;

	while (*pointer != '\0')
	{
		pointer++;
	}
	return (pointer - str);
}

/**
 * our_strcmp -compares two strings
 * @str1: pointer to first string
 * @str2: pointer to second string
 * Return: 0 if the strings are equal or negative value if
 * str1 < str2 or positive value if str1 is > str1
 */

int our_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
