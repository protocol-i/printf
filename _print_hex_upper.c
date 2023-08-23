#include "main.h"

/**
 * print_hex_upper - Print a number in uppercase hexadecimal format
 * @n: The number to print
 *
 * Return: Number of characters printed
 */
int print_hex_upper(unsigned int n)
{
	char buffer[32];
	char digits[] = "0123456789ABCDEF";
	int len = 0;
	int i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[len++] = digits[n % 16];
		n /= 16;
	}

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (len);
}
