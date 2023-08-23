#include <unistd.h>
#include "main.h"

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hexadecimal format
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_hex_lower(unsigned int n)
{
	char buffer[10];
	char hex_chars[] = "0123456789abcdef";
	int count = 0;
	int len = 0;
	int i;

	if (n == 0)
	{
		buffer[0] = '0';
		len = 1;
	}
	else
	{
		i = 0;
		while (n > 0)
		{
			buffer[i++] = hex_chars[n % 16];
			n /= 16;
		}
		len = i;
	}
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}
	count = write(1, buffer, len);
	return (count);
}
