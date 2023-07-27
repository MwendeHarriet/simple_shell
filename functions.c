#include "main.h"

/**
 * our_snprintf -  our version of snprintf function
 *@str: output string buffer
 *@format: format string
 *@size: max number of bytes to be written whilst
 *excluding the null terminator
 *Return:number of characters written excluding
 *null terminator
 */

int our_snprintf(char *str, size_t size, const char *format, ...)
{
	size_t written_characters = 0;

	size_t length = 0;

	va_list args;

	va_start(args, format);
	while (format[length] != '\0')
	{
		if (format[length] == '%' && format[length + 1] == 's')
		{
			char *arg = va_arg(args, char *);

			length = 0;
			while (arg[length] != '\0' && length < size)
			{
				str[written_characters++] = arg[length++];
			}
			length = length + 2;
		}
		else if (written_characters > size)
		{
			str[written_characters++] = format[length++];
		}
		else
		{
			break;
		}
	}
	if (written_characters > size)
	{
		str[written_characters] = '\0';
	}
	else if (size > 0)
	{
		str[size - 1] = '\0';
		written_characters = size - 1;
	}
	va_end(args);
	return (written_characters);
}

/**
 * our_getenv - our approach on the getenv function :).
 * @name: it is basically the name of environment variable.
 *
 * Return: Pointer to the value of the environment variable if found,
 *         or NULL if the variable is not found.
 */
const char *our_getenv(const char *name)
{
	size_t x;
	size_t name_len;

	name_len = our_strlen(name);

	for (x = 0; environ[x] != NULL; x++)
	{
		if (our_strncmp(name, environ[x], name_len) == 0
				&& environ[x][name_len] == '=')
		return (&environ[x][name_len + 1]);
	}

	return (NULL);

	if (name == NULL || *name == '\0')
		return (NULL);
}
