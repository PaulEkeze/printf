#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * bi_handler - handles %b format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int bi_handler(va_list ap)
{
	unsigned int decimal = va_arg(ap, unsigned int);
	int len;
	char *binary;

	if (decimal == 0)
		return (printchar('0'));
	len = get_bi_length(decimal);
	binary = malloc(len + 1);
	if (binary == NULL)
	{
		free(binary);
		return (0);
	}
	dec_to_bi(&binary[len - 1], decimal);
	binary[len] = '\0';

	return (printstr(binary));
}

/**
 * get_bi_length - get length of a number after
 * it's been converted to binary
 * @decimal: a number in base 10.
 * Return: length of a binary number.
 */
int get_bi_length(unsigned int decimal)
{
	if (decimal == 0)
		return (0);

	return (get_bi_length(decimal / 2) + 1);
}

/**
 * dec_to_bi - conver decimal number to binary
 * @binary: a string to store the binary number
 * @decimal: a number in base 10.
 * Return: void.
 */
void dec_to_bi(char *binary, unsigned int decimal)
{
	if (decimal == 0)
		return;

	dec_to_bi(binary - 1, decimal / 2);
	*binary = (decimal % 2) + '0';
}
