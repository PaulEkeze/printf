#include "main.h"
#include <limits.h>
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
	int i, k, len = 0;
	char *digit;
	int num_cp;
	int num = va_arg(ap, int);

	num_cp = num;
	if (num_cp < 0)
	{
		len += printchar('-');
		for (i = 0; num_cp < 0 ; i++)
			num_cp /= 10;
	}
	else
		for (i = 0; num_cp > 0 ; i++)
			num_cp /= 10;

	digit = malloc(i + 1);
	digit[i] = '\0';

	for (k = i - 1; k >= 0; k--)
	{
		if (num < 0)
			digit[k] = ((num % 10) * -1) + '0';
		else
			digit[k] = (num % 10) + '0';
		num /= 10;
	}

	return (printstr(digit) + len);
}
