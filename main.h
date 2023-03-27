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
	void (*func)(char *);
} fmt;

void printchar(char *);
void printstr(char *);
void (*get_fmt_func(char f))(char *);

#endif
