#include "main.h"
/**
 *_printf - prints formatted output to the standard output.
 * @format: format string.
 * @...: a variable number of arguments to be printed.
 */
int _print(const char *format, ...)
{
	va_list arg_list;
	int cha_print = 0;

	if (format == NULL)
		return -1;

	va_start(arg_list, format);

	while(*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			cha_print++
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(arg_list, int);
				write(1, &c, 1);
				cha_print++;
			}
			else if (*format == 's')
			{
				char *strg = va_arg(arg_list, char*);
				int str_len = 0;

				write(1, strg, str_len);
				cha_print += str_len;
			}
		}

		format++;
	}

	va_end(arg_list);
}
