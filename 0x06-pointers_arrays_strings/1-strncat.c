#include "main.h"

/**
  * _strlen - counts length of the string.
  * @s: string.
  *
  * Return: length of the string.
  */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
  * _strncat - concatenates n first characters of a string to the end of
  * another.
  * @dest: pointer to the initial string.
  * @src: pointer to the string to be concatenated at the end
  * of the initial one.
  * @n: number of characters to concatenate.
  * Return: pointer to the initial string.
  */
char *_strncat(char *dest, char *src, int n)
{
	int i, len0, len1;

	i = 0;
	len0 = _strlen(dest);
	len1 = _strlen(src);
	while (i < n)
	{
		if (i == len1)
			break;
		*(dest + len0 + i) = *(src + i);
		i++;
	}
	return (dest);
}
