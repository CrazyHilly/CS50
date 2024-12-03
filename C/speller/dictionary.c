// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = ('z' - 'a') * LENGTH * (LENGTH * 2);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int length = strlen(word);
    char input[length + 1];

    for (int i = 0; i < length + 1; i++)
    {
        input[i] = tolower(word[i]);
    }

    int size = hash(input);

    node *list = table[size];
    while (list != NULL)
    {
        if (strcmp(input, list->word) == 0)
        {
            return true;
        }
        list = list->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int word_size = strlen(word);
    int sum_size = 0;

    for (int i = word_size - 1; i >= 0; i--)
    {
        int x = word[i];
        sum_size += i * abs(x - 'a') + x + word_size;
    }

    return sum_size;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    memset(table, 0, sizeof(table));

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1] = "";
    while (1)
    {
        if (fgets(buffer, sizeof(buffer), file) != 0)
        {
            if (buffer[0] == '\n')
            {
                continue;
            }

            for (int i = 0; i < strlen(buffer); i++)
            {
                if (buffer[i] == '\n')
                {
                    buffer[i] = '\0';
                }
            }

            int index = hash(buffer);

            node *new = malloc(sizeof(node));
            if (new == NULL)
            {
                printf("Could not allocate memory\n");
                return false;
            }
            strcpy(new->word, buffer);
            new->next = table[index];
            table[index] = new;

            memset(buffer, 0, sizeof(buffer));
        }

        else
        {
            fclose(file);
            return true;
        }
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int size = 0;
    int duplicates = 0;
    for (int i = 0; i <= N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        node *list = table[i];

        while (list != NULL)
        {
            size++;
            list = list->next;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    bool freed = false;
    for (int i = 0; i <= N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        node *list = table[i];

        while (list != NULL)
        {
            node *temp = list;
            list = list->next;
            free(temp);
            freed = true;
        }
    }
    return freed;
}
