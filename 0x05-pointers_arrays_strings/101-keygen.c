#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
  * main - generates valid passwords for the program 101-crackme.
  * 
  * Return: always 0.
  */
int main(void)
{
	char s[64];
	int i, n, tmp, sum;
	time_t t;

	srand((unsigned) time(&t));
	sum = 0;
	n = 0xad4;
	i = 0;
	while (i < 64)
	{
		if (n - sum > 126)
			tmp = rand() % 83 + 44;
		else if (n - sum < 126 && n - sum > 44)
		{
			tmp = n - sum;
			*(s + i) = tmp;
			*(s + i + 1) = '\0';
			break;
		}
		else
		{
			i = 0;
			sum = 0;
			continue;
		}
		sum = sum + tmp;
		*(s + i) = tmp;
		*(s + i + 1) = '\0';
		i++;
	}
	printf("%s", s);
	return (0);
	
}
