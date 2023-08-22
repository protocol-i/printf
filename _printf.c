#include "main.h"

/**
 * _size - Calculate the number of digits in a positive integer.
 * @nb: The unsigned integer for which to calculate the size.
 *
 * Return: The size (number of digits) of the integer.
 */
int _size(unsigned int nb)
{
	int size = 0;

	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

/**
 * _putnbr - Print an integer to the standard output.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int _putnbr(int n)
{
	char *number;
	unsigned int nbr;
	int len = 0;
	int size;

	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		len++;
		write(1, "-", 1);
		nbr = n * (-1);
	}
	else
		nbr = n;
	size = _size(nbr);
	len += size;
	number = (char *)malloc((size + 1) * sizeof(char));
	if (!number)
		return (0);
	number[size--] = '\0';
	while (nbr > 0)
	{
		number[size--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	size = 0;
	while (number[size])
	{
		write(1, &number[size], 1);
		size++;
	}
	free(number);
	number = NULL;
	return (len);
}

/**
 *_printf - prints formatted output to the standard output.
 * @format: format string.
 * @...: a variable number of arguments to be printed.
 * Return: Number of characters printed
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
			cha_print += write(1, format, 1);
		else
		{
			format++;
			if (*format == '%')
				cha_print += write(1, "%", 1);
			else if (*format == 'r')
				cha_print += write(1, "r", 1);
			else if (*format == 'c')
			{
				char c  = va_arg(arg_list, int);

				cha_print += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *strg = va_arg(arg_list, char*);

				if (strg == NULL)
					strg = "(null)";
				while (*strg != '\0')
					cha_print += write(1, strg++, 1);
			}
			else if (*format == 'd' || *format == 'i')
				cha_print += _putnbr(va_arg(arg_list, int));
		}
		format++;
	}
	va_end(arg_list);
	return (cha_print);
}
