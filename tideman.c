#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

/* Custom function */
void merge_sort(pair mother_array[], int length);

/* Custom function */
void merge(pair left_array[], int lenL, pair right_array[], int lenR, pair mother_array[]);
void lock_pairs(void);

/* Custom function */
void recursive_function(pair original_pair, pair current_pair);
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

    // Loops through candidates
    for (int i = 0; i < candidate_count; i++)
    {

        // Checks if name is a valid candidate
        if (strcmp(name, candidates[i]) == 0)
        {

            // Update the ranks array
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    // Loop forward through primary preferences
    for (int i = 0; i < candidate_count; i++)
    {

        // Loop backwards through secondary preferences
        for (int j = candidate_count - 1; j != -1; j--)
        {
            if (j > i)
            {

                // Adds voter's preferences
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    // Loops through first candidate option
    for (int i = 0; i < candidate_count; i++)
    {

        // Loops through second candidate option
        for (int j = candidate_count - 1; j != -1; j--)
        {

            // Checks if first candidate is preferred over second
            if (i != j && (preferences[i][j] > preferences[j][i]))
            {

                // Records preferred candidate and updates pair count
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // Calls recursive merge sort function
    merge_sort(pairs, pair_count);

    return;
}

// Sorts arrays for merging
void merge_sort(pair mother_array[], int length)
{

    // Base case when array is of length 1
    if (length < 2)
    {
        return;
    }
    else
    {

        // Vairable 'half' stores the size of 'half' the mother_array
        int half = length / 2;

        // New arrays for left and right
        pair left_array[half];
        pair right_array[length - half];

        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (i < half)
            {
                // Transfers first half of mother_array into the left_array
                left_array[i] = mother_array[i];
            }
            else
            {
                // Transfers second half of mother_array into the right_array
                right_array[j] = mother_array[i];
                j++;
            }
        }


        // Recursive calls for the new left and right arrays
        merge_sort(left_array, half);
        merge_sort(right_array, length - half);


        // Variable lenL stores the length of the left_array
        int lenL = sizeof(left_array) / sizeof(left_array[0]);

        // Variable lenR stores the length of the right_array
        int lenR = sizeof(right_array) / sizeof(right_array[0]);


        // Final merge of the sorted left and right arrays
        merge(left_array, lenL, right_array, lenR, mother_array);
    }
}

// Merges arrays from sorting function
void merge(pair left_array[], int lenL, pair right_array[], int lenR, pair mother_array[])
{

    /* Variable i stores the smallest index in the left_array,
    j stores the smallest index in the right_array,
    and k stores the smallest index in the mother_array */
    int i = 0, j = 0, k = 0;


    // Runs through both left and right arrays while they both have index values
    while (i < lenL && j < lenR)
    {

        // Calculates the margin of victory between the winner and loser of the current pair
        int margin_left = preferences[left_array[i].winner][left_array[i].loser] -
                          preferences[left_array[i].loser][left_array[i].winner];
        int margin_right = preferences[right_array[j].winner][right_array[j].loser] -
                           preferences[right_array[j].loser][right_array[j].winner];

        /* Checks if the margin of the smallest index in the left array
        is graeter than or equal to the margin of the current smallest index
        of the right array. */
        if (margin_left >= margin_right)
        {

            /* If the above is true, the values stored in the smallest
            index in the left array are then transfered into the current
            smallest index of the mother array */
            mother_array[k] = left_array[i];
            i++;
        }
        else
        {
            mother_array[k] = right_array[j];
            j++;
        }
        k++;
    }

    // If only values in the left array are left to be sorted
    while (i < lenL)
    {
        mother_array[k] = left_array[i];
        i++;
        k++;
    }

    // If only values in the right array are left to be sorted
    while (j < lenR)
    {
        mother_array[k] = right_array[j];
        j++;
        k++;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    // Loop through pairs
    for (int i = 0; i < pair_count; i++)
    {

        // Assigns current pair's value to a constant variable
        pair original_pair = pairs[i];
        recursive_function(original_pair, original_pair);
    }
}

// Checks for cycles
void recursive_function(pair original_pair, pair current_pair)
{

    // Loops though locked pairs
    for (int i = 0; i < candidate_count; i++)
    {

        // If the winner of the current pair is the loser of another...
        if (locked[i][current_pair.winner] == true)
        {

            // Check if the winner of this new pair is the same as the original loser..
            if (i != original_pair.loser)
            {

                // If it isn't go down the rabbit hole looking for a cycle!
                current_pair.loser = current_pair.winner;
                current_pair.winner = i;
                recursive_function(original_pair, current_pair);
            }

            // Else if it is a cycle, then return nothing.
            return;
        }
    }

    // If it's not a cycle, lock in the pair
    locked[original_pair.winner][original_pair.loser] = true;
}


// Print the winner of the election
void print_winner(void)
{

    // Loops through columns in the locked array
    for (int i = 0; i < candidate_count; i++)
    {

        // Loops through rows in the locked array
        for (int j = 0; j < candidate_count; j++)
        {

            // If a value returns true, candidate in this column cannot be the winner
            if (locked[j][i])
            {
                break;
            }

            // If all values return false, then the candidate in this column is declared the winner
            else if (j == candidate_count - 1 && !locked[j][i])
            {
                printf("%s\n", candidates[i]);
            }
        }
    }

    return;
}
