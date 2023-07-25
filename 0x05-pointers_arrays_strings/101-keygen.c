#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to generate a random character within a specific range */
char generateRandomChar(int min, int max)
{
    return (char)(rand() % (max - min + 1)) + min;
}

/* Function to generate a random valid password */
void generateRandomPassword(int length)
{
    char password[13]; // Fixed-size array for the password, 12 characters + 1 for the null terminator
    int lowercase_min = 97;
    int lowercase_max = 122;
    int uppercase_min = 65;
    int uppercase_max = 90;
    int digit_min = 48;
    int digit_max = 57;
    int i; // Move the variable declaration here

    for (i = 0; i < length; i++)
    {
        int category = rand() % 3; // 0: lowercase, 1: uppercase, 2: digit

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

    password[length] = '\0'; // Null-terminate the password

    // Check for null bytes in the password and regenerate if found
    if (strchr(password, '\0') != NULL)
    {
        generateRandomPassword(length);
    }
    else
    {
        printf("%s\n", password);
    }
}

int main(void)
{
    int password_length = 12; // You can change this to your desired password length
    srand(time(NULL));        // Seed the random number generator with the current time

    generateRandomPassword(password_length);

    return 0;
}
