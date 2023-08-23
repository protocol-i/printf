#include <unistd.h>
#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
	char buffer[12];
	char octal_chars[] = "01234567";
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
			buffer[i++] = octal_chars[n % 8];
			n /= 8;
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
