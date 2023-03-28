#include "main.h"
#include <unistd.h>

/**
 * printchar - prints a character to stdout
 * @ch: the character to be printed
 * Return: 1 if successfull
 */
int printchar(char ch)
{
	char *str = ctos(ch);

	write(1, str, 1);

	return (1);
}

/**
 * printstr - prints a string literal to stdout
 * @str: the string to be printed
 * Return: number of characters printed
 */
int printstr(char *str)
{
	int len = get_length(str);

	write(1, str, len);

	return (len);
}
