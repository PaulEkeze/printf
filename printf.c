#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - prints formated string
 * @format: string containing formats
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list ap;
	int (*handler)(va_list);

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			handler = get_handler(format[i + 1]);

			if (handler != NULL)
			{
				len += handler(ap);
				i++;
				continue;
			}
		}
		len += printchar(format[i]);
	}
	va_end(ap);

	return (len);
}

/**
 * get_handler - get a function to handle a format in string
 * @specifier: the specifier or format
 * Return: a pointer to a function that hadles a format.
 */
int (*get_handler(char specifier))(va_list)
{
	int i;
	fhandler handlers[] = {
		{'c', char_handler},
		{'%', percent_handler},
		{'s', str_handler},
		{'i', int_handler},
		{'d', int_handler},
		{'\0', NULL}
	};

	for (i = 0; handlers[i].specifier; i++)
		if (handlers[i].specifier == specifier)
			return (handlers[i].handler);
	return (NULL);
}
