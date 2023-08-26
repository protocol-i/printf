#include "main.h"

/**
 * print_specifier - Handle specific specifiers.
 * @s: The specifier character.
 * @a: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int print_specifier(char s, va_list a)
{
	int p = 0, n;
	unsigned int tmp;
	char *t;

	if (s == 'c')
		p += _putchar(va_arg(a, int));
	else if (s == 's')
		p += (t = va_arg(a, char *)) ? _putstr(t) : _putstr("(null)");
	else if (s == 'd' || s == 'i')
		p += _putnbr(n = va_arg(a, int));
	else if (s == 'b')
		p += _putnbr_binary(va_arg(a, unsigned int));
	else if (s == '%')
		p += _putchar('%');
	else if (s == 'u')
		p += (tmp = va_arg(a, unsigned int), print_unsigned(tmp));
	else if (s == 'x')
		p += (tmp = va_arg(a, unsigned int), print_hex_lower(tmp));
	else if (s == 'o')
		p += (tmp = va_arg(a, unsigned int), print_octal(tmp));
	else if (s == 'X')
		p += (tmp = va_arg(a, unsigned int), print_hex_upper(tmp));
	else
		p += _putchar('%') + _putchar(s);

	return (p);
}
