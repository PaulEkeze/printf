#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf  - producing output according to a format
 * @format: a character string
 * project done by Team Badu, Paul
 * Return: the number of characters printed
**/
int _printf(const char *format, ...)
{
	int i, len = 0;
	int (*func)(char *);
	char *c, ch, *str;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		func = get_fmt_func('c');
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ch = va_arg(ap, int);
				c = ctoa(ch);
			}
			else if (format[i + 1] == 's')
			{
				c = va_arg(ap, char *);
				if (c == NULL)
					c = "(null)";
				func = get_fmt_func('s');
			}
			else if (format[i + 1] == '%')
				c = ctoa('%');
			else
			{
				str = ctoa(format[i]);
				len += func(str);
				continue;
			}
			len += func(c);
			i++;
			continue;
		}
		str = ctoa(format[i]);
		len += func(str);
	}
	va_end(ap);

	return (len);
}

/**
 * printchar - printing the chars in it
 * @str: the format specified
 * project done by Team Badu, Paul
 * Return: void
 *
**/
int printchar(char *str)
{
	write(1, str, 1);

	return (1);
}

/**
 * printstr - prints a string
 * @str: the string to be printed
 * Return: the length of printed string
 */
int printstr(char *str)
{
	int len = 0;

	for (; str[len]; len++)
		;
	write(1, str, len);

	return (len);
}

/**
 * get_fmt_func - can we get our specified format
 * @f: the format to get
 * project done by Team Badu, Paul
 * Return: pointer to a function
**/
int (*get_fmt_func(char f))(char *)
{
	int i;
	fmt formats[] = {
		{'c', printchar},
		{'s', printstr}
	};

	for (i = 0; i < 2; i++)
	{
		if (formats[i].format == f)
			return (formats[i].func);
	}
	return (NULL);
}

/**
 * ctoa - converts char to string
 * @c: the character
 * Return: a string
 */
char *ctoa(char c)
{
	char *str = malloc(2);

	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	str[0] = c;
	str[1] = '\0';

	return (str);
}
