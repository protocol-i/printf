#include "main.h"

/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, the number of characters written.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
