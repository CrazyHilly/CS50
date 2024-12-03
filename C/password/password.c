// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol; and no spaces\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper = false, lower = false, number = false, symbol = false;
    for (int i = 0, sum = 0; i < strlen(password); i++)
    {
        int letter = password[i];
        if (letter >= 65 && letter <= 90)
        {
            upper = true;
        }
        else if (letter >= 97 && letter <= 122)
        {
            lower = true;
        }
        else if (letter >= 48 && letter <= 57)
        {
            number = true;
        }
        else if
        (
            (letter >= 33 && letter <= 47)
            ||
            (letter >= 58 && letter <= 64)
            ||
            (letter >= 91 && letter <= 96)
            ||
            (letter >= 123 && letter <= 126)
        )
        {
            symbol = true;
        }
        else
        {
            return false;
        }
    }

    return upper && lower && number && symbol;
}