#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    string menu_name;
    float price;
    string name1;
    string name2;
    string name3;
}
menu_item;

menu_item* create_menu(void);
string add_items(void);
void get_cost(string order[], int order_length, menu_item menu[]);

int menu_length;

int main(void)
{
    menu_item *menu = create_menu();
    printf("\nWelcome to Beach Burger Snack!\nChoose from the following menu to order. Press enter when done.\n\n");
    for (int i = 0; i < menu_length; i++)
    {
        printf("%s\n", menu[i].menu_name);
    }
    printf("\n");

    int order_length = 1;
    string* order = malloc(order_length * sizeof(string));
    while (true)
    {
        order[order_length - 1] = add_items();
        if (order[order_length - 1][0] == '\0')
        {
            order_length--;
            break;
        }
        order_length++;
        order = realloc(order, order_length * sizeof(string));
    }

    if (order_length == 0)
    {
        printf("\nYour total cost is: $0\n");
    }
    else
    {
        get_cost(order, order_length, menu);
    }

    free(order);
    free(menu);
}

menu_item* create_menu(void)
{
/* To add new menu items, use the template below.
   Add your item name to the menu array located after a list of menu items.
   Update menu length accordingly.

    menu_item template;
    template.menu_name = "\0";
    template.price = 0;
    template.name1 = "\0";
    template.name2 = "\0";
    template.name3 = "\0";
    */

    menu_item burger;
    burger.menu_name = "Burger: $9.50";
    burger.price = 9.50;
    burger.name1 = "burger";
    burger.name2 = "\0";
    burger.name3 = "\0";

    menu_item veg_burger;
    veg_burger.menu_name = "Vegan Burger: $11.00";
    veg_burger.price = 11.00;
    veg_burger.name1 = "vegan burger";
    veg_burger.name2 = "veg burger";
    veg_burger.name3 = "\0";

    menu_item hot_dog;
    hot_dog.menu_name = "Hot Dog: $5.00";
    hot_dog.price = 5.00;
    hot_dog.name1 = "hot dog";
    hot_dog.name2 = "hot-dog";
    hot_dog.name3 = "\0";

    menu_item cheese_dog;
    cheese_dog.menu_name = "Cheese Dog: $7.00";
    cheese_dog.price = 7.00;
    cheese_dog.name1 = "cheese dog";
    cheese_dog.name2 = "cheese-dog";
    cheese_dog.name3 = "\0";

    menu_item fries;
    fries.menu_name = "Fries: $5.00";
    fries.price = 5.00;
    fries.name1 = "fries";
    fries.name2 = "\0";
    fries.name3 = "\0";

    menu_item cheese_fries;
    cheese_fries.menu_name = "Cheese Fries: $6.00";
    cheese_fries.price = 6.00;
    cheese_fries.name1 = "cheese fries";
    cheese_fries.name2 = "\0";
    cheese_fries.name3 = "\0";

    menu_item juice;
    juice.menu_name = "Cold Pressed Juice: $7.00";
    juice.price = 7.00;
    juice.name1 = "juice";
    juice.name2 = "pressed juice";
    juice.name3 = "cold pressed juice";

    menu_item cold_brew;
    cold_brew.menu_name = "Cold Brew: $3.00";
    cold_brew.price = 3.00;
    cold_brew.name1 = "brew";
    cold_brew.name2 = "cold brew";
    cold_brew.name3 = "\0";

    menu_item water;
    water.menu_name = "Water: $2.00";
    water.price = 2.00;
    water.name1 = "water";
    water.name2 = "\0";
    water.name3 = "\0";

    menu_item soda;
    soda.menu_name = "Soda: $2.00";
    soda.price = 2.00;
    soda.name1 = "soda";
    soda.name2 = "\0";
    soda.name3 = "\0";

    menu_item items[] = {burger, veg_burger, hot_dog, cheese_dog, fries, cheese_fries, juice, cold_brew, water, soda};
    menu_length = sizeof(items) / sizeof(items[0]);
    menu_item* menu = (menu_item*) malloc(menu_length * sizeof(menu_item));

    int i = 0;
    while (i < menu_length)
    {
        menu[i] = items[i];
        i++;
    }

    return menu;
}

string add_items(void)
{
    string order_item = get_string("Enter a food item: ");
    for (int i = 0; i < strlen(order_item); i++)
    {
        order_item[i] = tolower(order_item[i]);
    }
    return order_item;
}

void get_cost(string order[], int order_length, menu_item menu[])
{
    float total_price = 0;
    for (int i = 0; i < order_length; i++)
    {
        if (order[i][0] == '\0')
            {
                break;
            }
        for (int j = 0; j < menu_length; j++)
        {
            if
            (
                (strcmp(order[i], menu[j].name1) == 0) ||
                (strcmp(order[i], menu[j].name2) == 0) ||
                (strcmp(order[i], menu[j].name3) == 0)
            )
            {
                total_price += menu[j].price;
                break;
            }
        }
    }
    printf("\nYour total cost is: $%.2f\n\n", total_price);
}