#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string plaintext = get_string("plaintext:  ");
    int ASCII_ALPHABET[52];
    int ASCII_KEY[52];
    char KEY[100];

    for (int i = 0, j = 26; i < 26; i++, j++)
    {
        ASCII_ALPHABET[i] = i + 65;
        ASCII_ALPHABET[j] = j + 71;
    }

    for (int i = 0; i < 52; i++)
    {
        printf("%i ", ASCII_ALPHABET[i]);
    }
    printf("\n");
//    for (int i = 0; i < 26; i++)
 //   {
 //       KEY[i] = toupper(argv[i]);
 ///       KEY[i + 25] = tolower(argv[i])
 //       ASCII_KEY[i] = KEY[i];
 //       ASCII_KEY[i + 25] = KEY[i + 25];
//    }
    for (int i = 0; i < 52; i++)
    {
        printf("%i ", ASCII_KEY[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
    for (int i = 0; i <= strlen(plaintext); i++)
    {
        for (int j = 0; j <= 52; j++)
        {
            for (int y = 0; argv[i] > 0; y++)
            {
                if (plaintext[i] == ASCII_ALPHABET[y])
                {
 //                   ASCII_CIPHER[i] = argv[y];
                }
            }
        }
    }
    {
//        plaintext[i];
//        ASCII_PLAIN[i] = plaintext[i];
    }
    printf("\n");
}