#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generateRandomChar - Generate a random character within a specific range.
 * @min: The minimum ASCII value of the character.
 * @max: The maximum ASCII value of the character.
 *
 * Return: The randomly generated character.
 */
char generateRandomChar(int min, int max)
{
	return (char)(rand() % (max - min + 1)) + min;
}

/**
 * generateRandomPassword - Generate a random valid password.
 * @length: The length of the password to be generated.
 *
 * Return: None.
 */
void generateRandomPassword(int length)
{
	char password[length + 1]; /* +1 for the null terminator */
	int lowercase_min = 97;    /* ASCII value of 'a' */
	int lowercase_max = 122;   /* ASCII value of 'z' */
	int uppercase_min = 65;    /* ASCII value of 'A' */
	int uppercase_max = 90;    /* ASCII value of 'Z' */
	int digit_min = 48;        /* ASCII value of '0' */
	int digit_max = 57;        /* ASCII value of '9' */

	for (int i = 0; i < length; i++)
	{
		int category = rand() % 3; /* 0: lowercase, 1: uppercase, 2: digit */

		switch (category)
		{
			case 0:
				password[i] = generateRandomChar(lowercase_min, lowercase_max);
				break;
			case 1:
				password[i] = generateRandomChar(uppercase_min, uppercase_max);
				break;
			case 2:
				password[i] = generateRandomChar(digit_min, digit_max);
				break;
		}
	}

	password[length] = '\0'; /* Null-terminate the password */
	printf("Random Password: %s\n", password);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int password_length = 12; /* You can change this to your desired password length */

	srand(time(NULL)); /* Seed the random number generator with the current time */

	generateRandomPassword(password_length);

	return (0);
}
