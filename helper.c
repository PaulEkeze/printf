#include "main.h"

/**
 * get_length - gets the number of characters in a string
 * @str: the string
 * Return: length of str
 */
int get_length(char *str)
{
	int len = 0;

	for (; str[len]; len++)
		;

	return (len);
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

/**
 * get_bi_lengrh - get length of a number after
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
