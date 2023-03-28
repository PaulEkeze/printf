#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * format_handler - sturcture for handling formats in string
 * @specifier: a specific character or format
 * @handler: a pointer to a function to handle a format
 */
typedef struct format_handler
{
	char specifier;
	int (*handler)(va_list);
} fhandler;

int _printf(const char *format, ...);
char *ctos(char ch);
int printchar(char ch);
int char_handler(va_list ap);

#endif
