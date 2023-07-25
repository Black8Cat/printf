#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


/**
 * struct print - struct print
 *
 * @print: character
 * @struct: format struct
 * @f: the function associated
 */
typedef struct print
{
	char *print;
	int (*f)(va_list);
} print_t;


int _printf(const char *format, ...);
int format_char(va_list ap);
int format_string(va_list ap);
int format_percentage(va_list ap);
int format_int(va_list ap);
int print_numbers(int n);
int _putchar(char c);

#endif
