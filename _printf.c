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
	write(1, str, strlen(str) + 1);
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
	(void)ap;
	write(1, &"%", 1);
	return (1);
}

/**
 * _printf - a function that produces output
 *		according to a format
 *
 * @format: the string format
 * @...: the arguments
 *
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	int len = 0, i = 0, j;
	va_list ap;
	print_t print[] = {
		{"c", format_char},
		{"s", format_string},
		{"%", format_percentage},
		{NULL, NULL}
	};
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			i += 1;

			if (format[i] == '\0')
				return (-1);
			while (print[j].print)
			{
				if (format[i] == print[j].print[0])
				{
					len += print[j].f(ap);
				}
				j++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);

	return (len);
}
