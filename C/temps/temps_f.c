#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int temp;
}
city;

int city_number = 10;
city cities[10];

void sort_cities(void);

int main(void)
{
    int low = 18;
    int high = 37;

    printf("Average July temperature: \n");

    cities[0].name = "Lviv";
    cities[1].name = "Kyiv";
    cities[2].name = "Odesa";
    cities[3].name = "Rivne";
    cities[4].name = "Ternopil";
    cities[5].name = "Kharkiv";
    cities[6].name = "Lutsk";
    cities[7].name = "Uzhhorod";
    cities[8].name = "Poltava";
    cities[9].name = "Sumy";

    for (int i = 0; i < city_number; i++)
    {
        do
        {
            cities[i].temp = get_int("%s: ", cities[i].name);
        }
        while ((cities[i].temp <= low) || (cities[i].temp >= high));
    }
    printf("\n");

    sort_cities();

    for (int i = 0; i < city_number; i++)
    {
        printf("%s: %i\n", cities[i].name, cities[i].temp);
    }
}

void sort_cities(void)
{
    int end = city_number - 1;
    for (int i = 0; i < end; i++)
    {
        city first = cities[i];
        city second = cities[i + 1];

        if (first.temp < second.temp)
        {
            cities[i] = second;
            cities[i + 1] = first;
        }

        if (i == end - 1)
        {
            end--;
            i = -1;
        }
    }
}
