#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Average July temperature: \n");

    int cities = 10;

    int low = 18;
    int high = 37;

    string city[] = {"Lviv", "Kyiv", "Odesa", "Rivne", "Ternopil", "Kharkiv", "Lutsk", "Uzhhorod", "Poltava", "Sumy"};
    int temps[cities];

    for (int i = 0; i < cities; i++)
    {
        do
        {
            temps[i] = get_int("%s: ", city[i]);
        }
        while ((temps[i] <= low) || (temps[i] >= high));
    }

    int n = cities;
    do
    {
        for (int i = 1; i < n; i++)
        {
            if (temps[i - 1] < temps[i])
            {
                int temps_low = temps[i - 1];
                int temps_high = temps[i];
                string city_low = city[i - 1];
                string city_high = city[i];

                temps[i - 1] = temps_high;
                temps[i] = temps_low;
                city[i - 1] = city_high;
                city[i] = city_low;
            }
        }
        n--;
    }
    while (n > 1);

    for (int i = 0; i < cities; i++)
    {
        printf("%i ", temps[i]);
    }
    printf("\n");
}

