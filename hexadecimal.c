#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * hex_handler - handles %x %X format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int hex_handler(va_list ap)
{
	unsigned int decimal = va_arg(ap, unsigned int);
	int len;
	char *hexa;

	if (decimal == 0)
		return (printchar('0'));

	len = get_hex_length(decimal);
	hexa = malloc(len + 1);

	if (hexa == NULL)
	{
		free(hexa);
		return (0);
	}

	dec_to_hex(&hexa[len - 1], decimal);
	hexa[len] = '\0';

	return (printstr(hexa));
}

/**
 * get_hex_length - get length of a number after
 * it's been converted to hexadecimal.
 * @decimal: a number in base 10.
 * Return: length of a hexadecimal number.
 */
int get_hex_length(unsigned int decimal)
{
	if (decimal == 0)
		return (0);

	return (get_hex_length(decimal / 16) + 1);
}

/**
 * dec_to_hex - conver decimal number to hexa
 * @hexa: a string to store the hexa number
 * @decimal: a number in base 10.
 * Return: void.
 */
void dec_to_hex(char *hexa, unsigned int decimal)
{
	if (decimal == 0)
		return;

	dec_to_hex(hexa - 1, decimal / 16);
	*hexa = decimal % 16 == 10 ? 'a' :
		decimal % 16 == 11 ? 'b' :
		decimal % 16 == 12 ? 'c' :
		decimal % 16 == 13 ? 'd' :
		decimal % 16 == 14 ? 'e' :
		decimal % 16 == 15 ? 'f' :
		(decimal % 16) + '0';
}
