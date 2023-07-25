#include "main.h"

/**
 * format_char - formats character
 * @ap: argument pointer
 *
 * Return: number of bytes
 */
int format_char(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * format_string - formats string
 * @ap: argument pointer
 *
 * Return: number of bytes
 */
int format_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(null)";
	write(1, str, strlen(str));
	return (strlen(str));
}

/**
 * format_percentage - formats percentage
 * @ap: argument pointer
 *
 * Return: number of bytes
 */
int format_percentage(va_list ap)
{
	char c = '%';

	(void)ap;
	write(1, &c, 1);
	return (1);
}

/**
 * CheckFormat - checks if character is a valid specifer
 *
 * @c: charcter to check
 *
 * Return: 1 if character is a specifier, 0 otherwise
 */
int CheckFormat(char c)
{
	int i;
	char *specifiers = "cs%di";

	for (i = 0; specifiers[i]; i++)
		if (c == specifiers[i])
			return (1);

	return (0);
}
/**
 * _printf - a function that produces output
 *		according to a format
 * @format: the string format
 * @...: the arguments
 *
 * Return: number of chqrcters printed, -1 on error
 */
int _printf(const char *format, ...)
{
	int len = 0, i = 0, j;
	va_list ap;
	print_t print[] = {
		{"c", format_char},
		{"s", format_string},
		{"%", format_percentage},
		{"i", format_int},
		{"d", format_int},
		{NULL, NULL}
	};
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		j = 0;
		if (format[i] == '%' && CheckFormat(format[i + 1]))
		{
			i += 1;
			if (format[i] == '\0')
				return (-1);
			while (print[j].print)
			{
				if (format[i] == print[j].print[0])
					len += print[j].f(ap);
				j++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
