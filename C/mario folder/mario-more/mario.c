#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    for (int level = 1; level <= height; level++)
    {
        for (int white_space = height - level; white_space > 0; white_space--) //printing white space on the left side of the pyramid
        {
            printf(" ");
        }
        for (int hashtag = level * 2; hashtag > 0; hashtag--) //printing hashtags in a row
        {
            printf("#");
            if (hashtag == level + 1) //printing white space between the row of hashtags
            {
                printf("  ");
            }
        }
        printf("\n");

    }
}

