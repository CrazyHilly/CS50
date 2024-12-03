#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;
    do
    {
        size = get_int("Size: ");
    }
    while (size <= 0);

    int array[size];
    
    array[0] = 1;
    printf("%i\n", array[0]);

    for (int i = 1; i <= size - 1; i++)
    {
        array[i] = array[i - 1] * 2;
        printf("%i\n", array[i]);
    }
}