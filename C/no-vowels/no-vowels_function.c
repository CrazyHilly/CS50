// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string replace(string word, int length);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    int length = strlen(argv[1]);
    string word = argv[1];
    for (int i = 0; i < length; i++)
    {
        replace(word, length);
    }

    printf("%s\n", word);
}

// Replacing vowels with numbers
string replace(string word, int length)
{
    for (int i = 0; i < length; i++)
    {
        switch (tolower(word[i]))
        {
            case 97:
                word[i] = 54;
                break;
            case 101:
                word[i] = 51;
                break;
            case 105:
                word[i] = 49;
                break;
            case 111:
                word[i] = 48;
                break;
        }
    }
    return word;
}