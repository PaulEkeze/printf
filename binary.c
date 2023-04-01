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
