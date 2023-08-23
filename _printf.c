#include "main.h"

/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, the number of characters written.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
 * _putnbr_binary - Print an integer in binary to stdout.
 * @n: The integer to be printed.
 *
 * Return: On success, the number of characters written.
 */
int _putnbr_binary(unsigned int n)
{
	if (n / 2 != 0)
		_putnbr_binary(n / 2);
	return (_putchar((n % 2 == 0 ? '0' : '1')));
}

/**
 * print_specifier - Handle specific specifiers.
 * @specifier: The specifier character.
 * @arg_list: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int print_specifier(char specifier, va_list arg_list)
{
	int cha_print = 0;

	if (specifier == 'c')
	{
		char c = va_arg(arg_list, int);

		cha_print += _putchar(c);
	}
	else if (specifier == 's')
	{
		char *strg = va_arg(arg_list, char *);

		if (strg == NULL)
			strg = "(null)";
		cha_print += _putstr(strg);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(arg_list, int);

		cha_print += _putnbr(num);
	}
	else if (specifier == 'b')
	{
		unsigned int num = va_arg(arg_list, unsigned int);

		cha_print += _putnbr_binary(num);
	}
	else if (specifier == '%')
	{
		cha_print += _putchar('%');
	}
	else
	{
		cha_print += _putchar('%');
		cha_print += _putchar(specifier);
	}

	return (cha_print);
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
