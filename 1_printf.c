#include "main.h"

/**
 * format_int - formats integer
 * @ap: argument pointer
 *
 * Return: number of bytes
 */
int format_int(va_list ap)
{
	int len = 0, i = va_arg(ap, int);

	return (print_numbers(i, &len));
}

/**
 * print_numbers - a function that prints the numbers, from 0 to 9
 * @n: integer
 * @len: number of digits printed
 * Return: 0 (Success)
 */
int print_numbers(int n, int *len)
{
	unsigned int i;

	if (n < 0)
	{
		i = -n;
		*len += _putchar('-');
	}
	else
		i = n;

	if (i > 9)
		print_numbers(i / 10, len);
	*len += _putchar(i % 10 + '0');
	return (*len);
}
