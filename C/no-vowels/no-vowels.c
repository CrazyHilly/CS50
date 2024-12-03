// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        switch (argv[1][i])
        {
            case 97:
                argv[1][i] = 54;
                break;
            case 101:
                argv[1][i] = 51;
                break;
            case 105:
                argv[1][i] = 49;
                break;
            case 111:
                argv[1][i] = 48;
                break;
        }
        printf("%c", argv[1][i]);
    }
    printf("\n");
}
