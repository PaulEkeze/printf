#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * HEX_handler - handles %x %X format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int HEX_handler(va_list ap)
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

	dec_to_HEX(&hexa[len - 1], decimal);
	hexa[len] = '\0';

	return (printstr(hexa));
}

/**
 * dec_to_HEX - conver decimal number to hexa
 * @hexa: a string to store the hexa number
 * @decimal: a number in base 10.
 * Return: void.
 */
void dec_to_HEX(char *hexa, unsigned int decimal)
{
	if (decimal == 0)
		return;

	dec_to_HEX(hexa - 1, decimal / 16);
	*hexa = decimal % 16 == 10 ? 'A' :
		decimal % 16 == 11 ? 'B' :
		decimal % 16 == 12 ? 'C' :
		decimal % 16 == 13 ? 'D' :
		decimal % 16 == 14 ? 'E' :
		decimal % 16 == 15 ? 'F' :
		(decimal % 16) + '0';
}
