#include "main.h"
/**
 * _putnbr - Print an integer to stdout.
 * @n: The integer to be printed.
 *
 * Return: On success, the number of characters written.
 */
int _putnbr(int n)
{
	char *number;
	unsigned int nbr;
	int len = 0;
	int size;

	if (n == 0)
		return (_putchar('0'));
	if (n < 0)
	{
		len++;
		_putchar('-');
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
		_putchar(number[size]);
		size++;
	}
	free(number);
	number = NULL;
	return (len);
}
