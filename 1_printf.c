#include "main.h"

/**
 * format_int - formats integer
 * @ap: argument pointer
 *
 * Return: number of bytes
 */
int format_int(va_list ap)
{
	int i = va_arg(ap, int);
	int len = 0;

	len = print_numbers(i);
	return (len);
}

/**
 * print_numbers - a function that prints the numbers, from 0 to 9
 * @n: integer
 * Return: 0 (Success)
 */
int print_numbers(int n)
{
	unsigned int i;
	int len = 0;

	if (n < 0)
	{
		i = -n;
		len += _putchar('-');
	}
	else
		i = n;

	if (i > 9)
		print_numbers(i / 10);
	_putchar(i % 10 + '0');
}
