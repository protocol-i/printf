#include "main.h"

/**
 * _putstr - Write a string to stdout.
 * @str: The string to write.
 *
 * Return: On success, the number of characters written.
 */
int _putstr(const char *str)
{
	int len = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * _printf - Prints formatted output to the standard output.
 * @format: Format string.
 * @...: A variable number of arguments to be printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int cha_print = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
			cha_print += _putchar(*format);
		else
		{
			format++;
			cha_print += print_specifier(*format, arg_list);
		}
		format++;
	}
	va_end(arg_list);
	return (cha_print);
}

/**
 * _print_number - Print an integer
 * @n: The integer to be printed
 *
 * Return: Number of digits printed
 */
int _print_number(int n)
{
	int count = 0;
	int reversed = 0;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}
	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	while (reversed > 0)
	{
		count += _putchar(reversed % 10 + '0');
		reversed /= 10;
	}
	return (count);
}

/**
 * print_int - Prints an integer with flags
 * @args: The va_list containing the integer to print
 * @flags: The flags to apply
 *
 * Return: The number of characters printed
 */
int print_int(va_list args, const char *flags)
{
	int num = va_arg(args, int);
	int count = 0;

	if (flags)
	{
		while (*flags)
		{
			if (*flags == '+')
			{
				if (num >= 0)
					count += _putchar('+');
			}
			else if (*flags == ' ')
			{
				if (num >= 0)
					count += _putchar(' ');
			}
			else if (*flags == '#')
			{
				count += _putchar('#');
			}
			flags++;
		}
	}
	count += _print_number(num);
	return (count);
}
