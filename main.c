#include "main.h"
#include <stdio.h>
#include <stddef.h>

int main(void)
{
	int len1, len2;

	/* No format in string */
	len1 = _printf("Hello world\n");
	len2 = printf("Hello world\n");
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* Empty string */
	len1 = _printf("");
	len2 = printf("");
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* NULL */
	len1 = _printf(NULL);
	len2 = printf(NULL);
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* multiple %c formats with appropriate args*/
	len1 = _printf("Hello%c World%c\n", ',', '!');
	len2 = printf("Hello%c World%c\n", ',', '!');
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* unknown format combined with %c format with appropriate args */ 
	len1 = _printf("Hello%r World%c\n", '!');
	len2 = printf("Hello%r World%c\n", '!');
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* unknown format combined with %c format without appropriate args */ 
	len1 = _printf("Hello%r World%c\n"); /* prints nothing */
	len2 = printf("Hello%r World%c\n"); /* prints unknown character */
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	/* %% and %c format with appropriate args */ 
	len1 = _printf("World 100%c\n", '%');
	len2 = printf("World 100%c\n", '%');
	printf("Custom: %d\nOriginal: %d\n", len1, len2);

	return (0);
}
