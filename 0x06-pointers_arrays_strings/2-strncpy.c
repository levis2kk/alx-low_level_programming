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
  * _strncpy - takes a string and copies n characters from it to a buffer.
  * @dest: pointer to a buffer..
  * @src: string to be copied.
  * @n: number of characters to be copied.
  * Return: address to the buffer.
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
