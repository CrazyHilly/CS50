#include <stdio.h>

int main(void)
{
    int n = 100;
    int array[n];
    for (int i = 0; i <= n - 1; i++)
    {
        array[i] = i + 1;
        printf("%i ", array[i]);
    }
    printf("\n");
}