#include "main.h"

/**
 * _size - Calculate the number of digits in a positive integer.
 * @nb: The unsigned integer for which to calculate the size.
 *
 * Return: The size (number of digits) of the integer.
 */
int _size(unsigned int nb)
{
	int size = 0;

	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}
