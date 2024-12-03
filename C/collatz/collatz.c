#include <stdio.h>
#include <cs50.h>

int collatz(int number);

int main(void)
{
    int number;
    do
    {
        number = get_int("Number: ");
    }
    while (number < 1);
    printf("%i\n", collatz(number));
}

int collatz(int number)
{
    if (number == 1)
    {
        return 0;
    }
    else if (number % 2 == 0)
    {
        int res = 1 + collatz(number / 2);
        return res;
    }
    else
    {
        int res = 1 + collatz(3 * number + 1);
        return res;
    }
}