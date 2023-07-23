#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>

/**
 * struct print - struct print
 *
 * @struct: format struct
 * @f: the function associated
 */
typedef struct print
{
	char *print;
	void (*f)(char *, va_list);
} print_t;


int _printf(const char *format, ...);

#endif
