#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

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
		for (i = 0; num_cp < 0; i++)
			num_cp /= 10;
	}
	else if (num_cp > 0)
		for (i = 0; num_cp > 0; i++)
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
