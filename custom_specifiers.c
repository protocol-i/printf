#include "main.h"

/**
 * handle_S_specifier - Handle custom 'S' specifier.
 * @arg_list: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_S_specifier(va_list arg_list)
{
	char *strg = va_arg(arg_list, char *);
	int cha_print = 0;

	if (strg == NULL)
		strg = "(null)";

	while (*strg)
	{
		if (*strg < 32 || *strg >= 127)
		{
			cha_print += _putchar('\\');
			cha_print += _putchar('x');
			cha_print += _putchar('0');
			cha_print += _putchar(to_hex_digit((*strg >> 4) & 0xF));
			cha_print += _putchar(to_hex_digit(*strg & 0xF));
		}
		else
		{
			cha_print += _putchar(*strg);
		}
		strg++;
	}

	return (cha_print);
}

/**
 * to_hex_digit - Convert a nibble to its hexadecimal character representation.
 * @value: The nibble value.
 *
 * Return: Hexadecimal character representation.
 */
char to_hex_digit(unsigned char value)
{
	if (value < 10)
		return ('0' + value);
	else
		return ('A' + (value - 10));
}
