#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * oct_handler - handles %b format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int oct_handler(va_list ap)
{
	unsigned int decimal = va_arg(ap, unsigned int);
	int len;
	char *octal;

	if (decimal == 0)
		return (printchar('0'));

	len = get_oct_length(decimal);
	octal = malloc(len + 1);

	if (octal == NULL)
	{
		free(octal);
		return (0);
	}

	dec_to_oct(&octal[len - 1], decimal);
	octal[len] = '\0';

	return (printstr(octal));
}

/**
 * get_oct_length - get length of a number after
 * it's been converted to octal.
 * @decimal: a number in base 10.
 * Return: length of a octal number.
 */
int get_oct_length(unsigned int decimal)
{
	if (decimal == 0)
		return (0);

	return (get_oct_length(decimal / 8) + 1);
}

/**
 * dec_to_oct - conver decimal number to octal
 * @octal: a string to store the octal number
 * @decimal: a number in base 10.
 * Return: void.
 */
void dec_to_oct(char *octal, unsigned int decimal)
{
	if (decimal == 0)
		return;

	dec_to_oct(octal - 1, decimal / 8);
	*octal = (decimal % 8) + '0';
}
