#include "main.h"
#include <stdlib.h>

/**
 * ctos - converts character (ch) to a string (str)
 * @ch: the character to be converted
 * Return: converted string (str)
 */
char *ctos(char ch)
{
	char *str = malloc(2);

	if (str == NULL)
		return (NULL);

	str[0] = ch;
	str[1] = '\0';

	return (str);
}

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
