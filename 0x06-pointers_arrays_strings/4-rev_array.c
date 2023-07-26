#include "main.h"

/**
 * reverse_array - prints array elements in reverse.
 * @a: array of integers.
 * @n: number of elements of the array.
 */
void reverse_array(int *a, int n)
{
	int i, tmp;

	i = 0;
	while (i < (n / 2))
	{
		tmp = *(a + i);
		*(a + i) = *(a + (n - 1) - i);
		*(a + (n - 1) - i) = tmp;
		i++;
	}
}
