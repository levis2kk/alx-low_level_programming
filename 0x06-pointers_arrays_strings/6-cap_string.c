#include "main.h"

/**
  * cap_string - capitalize every word of a string.
  * @s: string input.
  * Return: pointer to initial string.
  */
char *cap_string(char *s)
{
	int i, tmp;

	i = 0;
	while (*(s + i) != '\0')
	{
		if ((i == 0) && (*s < 123 && *s > 96))
			*s = 65 + (*s - 97);
		if (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n'
				|| *(s + i) == ',' || *(s + i) == ';' ||
				*(s + i) == '.' || *(s + i) == '!' ||
				*(s + i) == '?' || *(s + i) == '"' ||
				*(s + i) == '(' || *(s + i) == ')' ||
				*(s + i) == '{' || *(s + i) == '}')
		{
			tmp = *(s + i + 1);
			if (tmp < 123 && tmp > 96)
				*(s + i + 1) = 65 + (tmp - 97);

		}
		i++;
	}
	return (s);
}
