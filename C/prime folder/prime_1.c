#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int end = 0;
    while (end < 1)
    {
        end = get_int("Specify end number: ");
    }
    for (int i = 1; i <= end; i++)
    {
        if (i <= 3)
        {
            printf("%i\n", i);
        }
        else if ((i >= 4) && (i % 2 != 0))
        {
            printf("%i\n", i);
        }
    }
}