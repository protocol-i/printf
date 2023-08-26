#include "main.h"
/**
 * print_specifier - Handle specific specifiers.
 * @specifier: The specifier character.
 * @arg_list: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int print_specifier(char s, va_list a)
{
	int p = 0;
	char *t;
	int n;
	unsigned int u, x, o, X;

	switch (s)
	{
		case 'c':
			p += _putchar(va_arg(a, int));
			break;
		case 's':
			t = va_arg(a, char *);
			p += t ? _putstr(t) : _putstr("(null)");
			break;
		case 'd': case 'i':
			p += _putnbr(n = va_arg(a, int));
			break;
		case 'b':
			p += _putnbr_binary(va_arg(a, unsigned int));
			break;
		case '%':
			p += _putchar('%');
			break;
		case 'u':
			p += print_unsigned(u = va_arg(a, unsigned int));
			break;
		case 'x':
			p += print_hex_lower(x = va_arg(a, unsigned int));
			break;
		case 'o':
			p += print_octal(o = va_arg(a, unsigned int));
			break;
		case 'X':
			p += print_hex_upper(X = va_arg(a, unsigned int));
			break;
		default:
			p += _putchar('%');
			p += _putchar(s);
	}

	return (p);
}
