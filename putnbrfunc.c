/**
 * _putnbr - Print an integer to the standard output.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int _putnbr(int n)
{
	char *number;
	unsigned int nbr;
	int len = 0;
	int size;

	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		len++;
		write(1, "-", 1);
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
		write(1, &number[size], 1);
		size++;
	}
	free(number);
	number = NULL;
	return (len);
}
