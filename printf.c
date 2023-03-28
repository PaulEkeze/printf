#include "main.h"

/**
 * _printf - prints formated string
 * @format: string containing formats
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, len = 0;

	for (i = 0; format[i]; i++)
	{
		len += printchar(format[i]);
	}

	return (len);
}
