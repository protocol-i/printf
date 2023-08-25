#include "main.h"

/**
 * handle_p_specifier - Handle custom p specifier (prints a pointer).
 * @arg_list: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_p_specifier(va_list arg_list)
{
	void *ptr = va_arg(arg_list, void *);

	int cha_print = 0;

	cha_print += _putstr("0x");
	cha_print += print_hex_lower((unsigned long)ptr);

	return (cha_print);
}
