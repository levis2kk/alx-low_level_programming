#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase ten times
 *
 * Description: Prints the lowercase alphabet ten times, followed by a new line.
 */
void print_alphabet_x10(void)
{
	int i;
	char letter;

	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
	}

	_putchar('\n');
}
