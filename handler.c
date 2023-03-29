#include "main.h"
#include <stdlib.h>
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

/**
 * int_handler - handles %i and %d format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int int_handler(va_list ap)
{
	int i, j, k, len = 0;
	char *digit;
	int num = va_arg(ap, int);

	if (num < 0)
	{
		num *= -1;
		len += printchar('-');
	}

	for (j = 1, i = 10; num > i; i *= 10, j++)
		;

	digit = malloc(j + 1);
	digit[j] = '\0';

	for (k = j - 1; k >= 0; k--)
	{
		digit[k] = (num % 10) + '0';
		num /= 10;
	}

	return (printstr(digit) + len);
}
