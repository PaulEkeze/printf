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
