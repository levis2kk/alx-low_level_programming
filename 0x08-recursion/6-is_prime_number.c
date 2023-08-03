#include "main.h"

/**
 * is_prime - calculate if the number is prime.
 * @n: natural number
 * @i: counter or divisor of n.
 *
 * Return: 1 if is prime 0 otherwise.
 */
int is_prime(int n, int i)
{
	if (n % i == 0)
	{
		return (0);
	}
	else if (i == (n - 1) && n % i != 0)
	{
		return (1);
	}
	else
	{
		return (is_prime(n, i + 1));
	}
}
