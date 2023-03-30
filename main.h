#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_handler - sturcture for handling formats in string
 * @specifier: a specific character or format
 * @handler: a pointer to a function to handle a format
 */
typedef struct format_handler
{
	char specifier;
	int (*handler)(va_list);
} fhandler;

int _printf(const char *format, ...);
int printchar(char ch);
int char_handler(va_list ap);
int (*get_handler(char specifier))(va_list);
int percent_handler(va_list ap __attribute__((unused)));
int get_length(char *str);
int printstr(char *str);
int str_handler(va_list ap);
int int_handler(va_list ap);
void dec_to_bi(char *binary, int decimal);
int bi_handler(va_list ap);
int get_bi_length(int decimal);

#endif
