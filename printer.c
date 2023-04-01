#include "main.h"
#include <unistd.h>

/**
 * printchar - prints a character to stdout
 * @ch: the character to be printed
 * Return: 1 if successfull
 */
int printchar(char ch)
{
	write(1, &ch, 1);

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
