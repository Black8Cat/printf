#include "main.h"

/**
 * format_char - formats character
 * @ap: argument pointer
 */
void format_char(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
}

/**
 * format_string - formats string
 * @ap: argument pointer
 */
void format_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	write(1, str, strlen(str));
}

/**
 * format_percentage - formats percentage
 * @ap: argument pointer
 */
void format_percentage(va_list ap)
{
	write(1, &"%", 1);
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
	int i = 0, j;
	va_list ap;
	print_t print[] = {
		{"c", format_char},
		{"s", format_string},
		{"%", format_percentage},
		{NULL, NULL}
	};

	va_start(ap, format);
	while (format && format[i])
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
					print[j].f(ap);
				}
				j++;
			}
		}
		else
			_printf("%c", format[i]);
		i++;
	}
	_printf("\n");
	va_end(ap);

	return (0);
}
