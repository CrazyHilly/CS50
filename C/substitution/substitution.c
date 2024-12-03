#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key_length = 0;
    int ASCII_KEY[52];

    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];

//Converting argv key to array of ASCII named ASCII_KEY starting from upper- and ending with lowercase
    for (int i = 0; key[i] > 0; i++)
    {

        int key_letter = key[i];
        if (key_letter < 65 || (key_letter > 90 && key_letter < 97) || key_letter > 122)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int j = 0; j < 52; j++)
        {
            if (key_letter == ASCII_KEY[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        ASCII_KEY[i] = toupper(key_letter);
        ASCII_KEY[i + 26] = tolower(key_letter);
        key_length = i + 1;
    }

    if (key_length < 26 || key_length > 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Creating array of alphabet in ASCII named ASCII_ALPHABET starting from upper- and ending with lowercase
    string plaintext = get_string("plaintext:  ");
    int text_length = strlen(plaintext);
    int ASCII_ALPHABET[52];

    for (int i = 0, j = 26; i < 26; i++, j++)
    {
        ASCII_ALPHABET[i] = i + 65;
        ASCII_ALPHABET[j] = j + 71;
    }

    //Converting plaintext to ciphertext and saving it in ASCII_CIPHER array
    int ASCII_CIPHER[text_length];
    printf("ciphertext: ");
    for (int i = 0; i < text_length; i++)
    {
        if (plaintext[i] == 0)
        {
            return 0;
        }
        for (int j = 0; j < 52; j++)
        {
            if (plaintext[i] == ASCII_ALPHABET[j])
            {
                ASCII_CIPHER[i] = ASCII_KEY[j];
                break;
            }
            else
            {
                ASCII_CIPHER[i] = plaintext[i];
            }
        }
        printf("%c", ASCII_CIPHER[i]);
    }
    printf("\n");

}