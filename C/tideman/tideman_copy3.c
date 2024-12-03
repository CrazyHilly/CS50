#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i]) != 0)
        {
            continue;
        }

        for (int j = 0; j < rank; j++)
        {
            if (ranks[j] == i)
            {
                return false;
            }
        }

        ranks[rank] = i;
        return true;
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    printf("record_preferences:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("add_pairs:\n");
    for (int i = 0, k = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((preferences[i][j] - preferences[j][i]) <= 0)
            {
                continue;
            }
            pairs[k].winner = i;
            pairs[k].loser = j;
            k++;
            printf("%i, %i;  ", pairs[k - 1].winner, pairs[k - 1].loser);
        }
        pair_count = k;
    }
    printf("\n\npair_count = %i\n\n", pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    printf("difference:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("%i, %i;  ", pairs[i].winner, pairs[i].loser);
    }


    int difference[pair_count];

    for (int i = 0; i < pair_count; i++)
    {
        int first_winner = pairs[i].winner;
        int first_loser = pairs[i].loser;
        int first_pref = preferences[first_winner][first_loser];

        int second_winner;
        int second_loser;
        int second_pref = 0;

        for (int j = 0; j < pair_count; j++)
        {
            if (i == j)
            {
                continue;
            }
            int next_winner = pairs[j].winner;
            int next_loser = pairs[j].loser;

            if (!((first_winner == next_loser) && (first_loser == next_winner)))
            {
                continue;
            }

            second_winner = pairs[j].winner;
            second_loser = pairs[j].loser;
            second_pref = preferences[second_winner][second_loser];

            break;
        }

        difference[i] = first_pref - second_pref;
    }

    printf("\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf(" %i     ", difference[i]);
    }

    for (int i = 0; i < pair_count; i++)
    {
        int change = 0;

        for (int j = 0; j < (pair_count - i - 1); j++)
        {
            if (difference[j] >= difference[j + 1])
            {
                continue;
            }

            int temp_dif = difference[j];
            difference[j] = difference[j + 1];
            difference[j + 1] = temp_dif;

            pair temp_pair = pairs[j];
            pairs[j] = pairs[j + 1];
            pairs[j + 1] = temp_pair;

            change++;
        }

        if (change == 0)
            {
                break;
            }
    }

    printf("\n\n");
    printf("sort_pairs:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("%i, %i - %i\n", pairs[i].winner, pairs[i].loser, difference[i]);
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    printf("\nlock_pairs:\n");

    bool losers[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        losers[i] = false;
    }

    for (int i = 0, counter = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if (losers[loser] == false)
        {
            counter++;
            if (counter == candidate_count)
            {
                break;
            }
            losers[loser] = true;
        }

        locked[winner][loser] = true;

        if (locked[loser][winner] == true)
        {
            locked[winner][loser] = false;
            continue;
        }

        printf("%i, %i\n", winner, loser);


/*
        for (int j = i - 1; j >= 0; j--)
        {
            if (pairs[i].winner == pairs[j].loser)
            {
                locked[pairs[i].winner][pairs[i].loser] = false;
                break;
            }
        }
*/

    }
    printf("\n");
    return;
}

// Print the winner of the election
void print_winner(void)
{
    printf("print_winner:\n\n");
    for (int winner = 0; winner < candidate_count; winner++)
    {
        for (int loser = 0; loser < candidate_count; loser++)
        {
            if (locked[loser][winner] == true)
            {
                break;
            }
            if (loser == candidate_count - 1)
            {
                printf("%s\n", candidates[winner]);
            }
        }
    }
}


/*
            for (int k = 0; k < candidate_count; k++)
            {
                if (locked[k][i] == true)
                {
                    break;
                }
                if (k == candidate_count - 1)
                {
                    printf("%s\n\n", candidates[i]);
                    return;
                }
            }

        }
    }
}
*/