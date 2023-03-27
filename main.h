#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

/**
 * struct format - our format structure
 * @format: char string
 * @func: function to be called
**/

typedef struct format
{
	char format;
	int (*func)(char *);
} fmt;

int printchar(char *);
int printstr(char *);
int (*get_fmt_func(char f))(char *);
char *ctoa(char);

#endif
