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
