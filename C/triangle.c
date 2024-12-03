#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float a, b, c;
    do
    {
        a = get_float("First side: ");
        b = get_float("Second side: ");
        c = get_float("Third side: ");
    }
    while (a <= 0 || b <= 0 || c <= 0);

    if (valid_triangle(a, b, c) == true)
    {
        printf("The triangle can be built\n");
    }
    else
    {
        printf("The triangle cannot be built\n");
    }
}

bool valid_triangle(float a, float b, float c)
{
    if ((a + b > c) && (b + c > a) && (c + a > b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

