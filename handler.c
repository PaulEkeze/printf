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
	int i, len = 0, num = va_arg(ap, int), num_cp = num;
	char *digit;

	if (num_cp < 0)
	{
		len += printchar('-');
		for (i = 0; num_cp < 0 ; i++)
			num_cp /= 10;
	}
	else if (num_cp > 0)
		for (i = 0; num_cp > 0 ; i++)
			num_cp /= 10;
	else
		return (printchar('0'));

	digit = malloc(i + 1);
	if (digit == NULL)
	{
		free(digit);
		return (0);
	}

	digit[i] = '\0';

	for (i = i - 1; i >= 0; i--)
	{
		if (num < 0)
			digit[i] = ((num % 10) * -1) + '0';
		else
			digit[i] = (num % 10) + '0';
		num /= 10;
	}

	return (printstr(digit) + len);
}

/**
 * binary_handler - handles %b format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int bi_handler(va_list ap)
{
	int decimal = va_arg(ap, int);
	int len = get_bi_length(decimal);
	char *binary = malloc(len + 1);

	dec_to_bi(&binary[len - 1], decimal);
	binary[len] = '\0';
	return (printstr(binary));
}

