#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * nonp_handler - prints non printable characters
 * @ap: list of arguments
 * Return: number of characters printed
 */
int nonp_handler(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, len = 0;
	char *hexa = malloc(3);

	if (hexa == NULL)
	{
		free(hexa);
		return (0);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			if (str[i] < 16)
				hexa[0] = '0';

			dec_to_HEX(&hexa[1], str[i]);
			hexa[2] = '\0';
			len += printstr("\\x");
			len += printchar(hexa[0]);
			len += printchar(hexa[1]);
			continue;
		}

		len += printchar(str[i]);
	}

	return (len);
}
