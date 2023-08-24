#include "main.h"
/**
 * _putnbr_binary_recursive - Print an integer in binary to stdout.
 * @n: The integer to be printed.
 *
 * Return: On success, the number of characters written.
 */
int _putnbr_binary_recursive(unsigned int n)
{
	if (n >= 2)
		return (_putnbr_binary_recursive(n / 2) + _putchar(n % 2 + '0'));
	else
		return (_putchar(n + '0'));
}

/**
 * _putnbr_binary - Print an integer in binary to stdout.
 * @n: The integer to be printed.
 *
 * Return: On success, the number of characters written.
 */
int _putnbr_binary(unsigned int n)
{
	return (_putnbr_binary_recursive(n));
}
