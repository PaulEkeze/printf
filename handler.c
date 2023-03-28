#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * char_handler - handles %c format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int char_handler(va_list ap)
{
	char ch = va_arg(ap, int);

	return (printchar(ch));
}

/**
 * percent_handler - handles %% format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int percent_handler(va_list ap __attribute__((unused)))
{
	return (printchar('%'));
}

/**
 * str_handler - handles %s format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int str_handler(va_list ap)
{
	char *str = va_arg(ap, char *);

	if (str == NULL)
		return (printstr("(null)"));

	return (printstr(str));
}
