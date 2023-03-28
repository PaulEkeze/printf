#include "main.h"
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
