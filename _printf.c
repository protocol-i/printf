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
		{
			cha_print += write(1, format, 1);
			format++;
			continue;
		}

		format++;
		if (*format == '\0') /* Handle trailing '%' */
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
		}
		format++;
	}
	va_end(arg_list);
	return (cha_print);
}
