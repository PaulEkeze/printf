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
