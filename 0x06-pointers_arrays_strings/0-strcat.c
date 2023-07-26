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
  * _strcat - concatenates a string to the end of another.
  * @dest: pointer to the initial string.
  * @src: pointer to the string to be concatenated at the end
  * of the initial one.
  * Return: pointer to the initial string.
  */
char *_strcat(char *dest, char *src)
{
	int i, len0, len1;

	i = 0;
	len0 = _strlen(dest);
	len1 = _strlen(src);
	while (i < len1)
	{
		*(dest + len0 + i) = *(src + i);
		i++;
	}
	return (dest);
}
