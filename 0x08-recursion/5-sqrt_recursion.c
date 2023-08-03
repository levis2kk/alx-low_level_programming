#include "main.h"

/**
 * power_operation - returns the natural square root of a number.
 * @n: integer variable of given number
 * @i: iterator.
 * Return: square root or -1.
 */

int power_operation(int n, int i)
{
if (i % (n / i) == 0)
{
if (i * (n / i) == n)
{
return (i);
}
else
{
return (-1);
}
}
return (0 + power_operation(n, (i + 1)));
}
