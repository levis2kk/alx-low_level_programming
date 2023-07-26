#include "main.h"

/**
  * string_toupper - changes all lowercase letters to uppercase letters.
  * @s: pointer to the string.
  * Return: pointer to the string.
  */
char *string_toupper(char *s)
{
	int i, tmp;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) > 96 && *(s + i) < 123)
		{
			tmp = *(s + i) - 97;
			*(s + i) = 65 + tmp;
		}
		i++;
	}
	return (s);
}
