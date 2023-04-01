#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * unsigned_handler - handles %u format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int unsigned_handler(va_list ap)
{
	unsigned int uint = va_arg(ap, unsigned int);
	unsigned int uint_cp = uint;
	char *digits;
	int i;

	if (uint == 0)
		return (printchar('0'));

	for (i = 0; uint_cp > 0; i++)
		uint_cp /= 10;

	digits = malloc(i + 1);

	if (digits == NULL)
	{
		free(digits);
		return (0);
	}

	for (i = i - 1; i >= 0; uint /= 10, i--)
		digits[i] = (uint % 10) + '0';

	digits[i] = '\0';

	return (printstr(digits));
}
