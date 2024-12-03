#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number <= 1) //less-equal than 1
    {
        return false;
    }
    else if (number > 1 && number <= 3) //from 1 to incl. 3
    {
        return true;
    }
    else if (number % 2 != 0) //odd numbers greater than 3
    {
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0) 
            {
                return false;
            }
        }
        return true;
    }

    return false;  //even numbers greater than 3
}
