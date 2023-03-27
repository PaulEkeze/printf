#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf  - producing output according to a format
 * @format: a character string
 * project done by Team Badu, Paul
 * Return: the number of characters printed
 *
**/

int _printf(const char *format, ...)
{
	int i;
	void (*func)(char *);
	char *c;
	char *str;
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		func = get_fmt_func('c');
		if (format[i] == '%')
		{
			c = (char *) va_arg(ap, char *);
			printf("%p\n", c);
			if (format[i + 1] == 's') 
			{
				func = get_fmt_func('s');
				i++;
				continue;
			}
			func(c);
			i++;
			continue;
		}
		str = malloc(2);
		if (str == NULL)
		{
			free(str);
			return (0);
		}
		str[0] = format[i];
		str[1] = '\0';
		func(str);
	}
	va_end(ap);
	func("\n");

	return (0);
}

/**
 * printchar - printing the chars in it
 * @c: the format specified
 * project done by Team Badu, Paul
 * Return: void
 *
**/

void printchar(char *c)
{
	char *str = malloc(2);

	if (str == NULL)
	{
		free(str);
		return;
	}
	str[0] = c[0];
	str[1] = '\0';
	write(1, str, 1);
}

void printstr(char *str)
{
	int len = 0;

	for (; str[len]; len++)
		;
	write(1, str, len);
}

/**
 * get_fmt_func - can we get our specified format
 * @f: the format to get
 * project done by Team Badu, Paul
 * Return: pointer to a function
 *
**/

void (*get_fmt_func(char f))(char *)
{
	int i;
	fmt formats[] = {
		{'c', printchar},
		{'s', printstr}
	};

	for (i = 0; i < 2; i++)
	{
		if (formats[i].format == f)
		{
			return (formats[i].func);
		}
	}
}
