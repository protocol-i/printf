#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
	char buffer[10];
	char temp_buffer[10];
	int count = 0;
	int len = 0;
	int i = 0;

	do {
		temp_buffer[i++] = (n % 10) + '0';
		n /= 10;
	} while (n != 0);

	len = i;

	for (i = len - 1; i >= 0; i--)
		buffer[len - i - 1] = temp_buffer[i];
	count = write(1, buffer, len);
	return (count);
}
