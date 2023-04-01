#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * str_handler - handles %s format in string
 * @ap: list of arguments
 * Return: number of characters printed
 */
int str_handler(va_list ap)
{
	char *str = va_arg(ap, char *);

	if (str == NULL)
		return (printstr("(null)"));

	return (printstr(str));
}
