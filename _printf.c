#include "main.h"

/**
 * _printf - prints formatted output to the standard output.
 * @format: format string.
 * @...: a variable number of arguments to be printed.
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int cha_print = 0;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
			cha_print += write(1, format, 1);
<<<<<<< HEAD
		else
=======
			format++;
			continue;
		}

		format++;
		if (*format == '\0')
>>>>>>> 10c3de64a8339915ae83393330ee98a3fa46be99
		{
			cha_print += write(1, "%", 1);
			break;
		}
		else if (*format == 'c')
		{
			char c = va_arg(arg_list, int);

			cha_print += write(1, &c, 1);
		}
		else if (*format == 's')
		{
			char *strg = va_arg(arg_list, char*);

<<<<<<< HEAD
				write(1, &c, 1);
				cha_print++;
			}
			else if (*format == 's')
			{
				char *strg = va_arg(arg_list, char*);
				if (strg == NULL)
					strg = "(null)";
				cha_print += write(1, strg,strlen(strg));
			}
			else if (*format == 'd' || *format == 'i')
				cha_print += _putnbr(va_arg(arg_list, int));
=======
			if (strg == NULL)
				strg = "(null)";
			int str_len = strlen(strg);

			cha_print += write(1, strg, str_len);
		}
		else if (*format == 'd' || *format == 'i')
		{
			cha_print += _putnbr(va_arg(arg_list, int));
		}
		else if (*format == '%')
		{
			cha_print += write(1, "%", 1);
>>>>>>> 10c3de64a8339915ae83393330ee98a3fa46be99
		}
		format++;
	}
	va_end(arg_list);
	return (cha_print);
}
