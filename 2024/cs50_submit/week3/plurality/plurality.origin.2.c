#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        else
        {
            // candidates[i].votes++;
            vote(name);
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    candidate equivalent[candidate_count];
    int max_vote = 0, r_times = 0, checker = 0;
    //compear candidates
    for(int i = 1; i < candidate_count ; i++)
    {
        if(candidates[max_vote].votes < candidates[i].votes)
            max_vote++;
    } 
// if have equivalent add equivalent in new array
    for(int j = 1; j < candidate_count; j++)
    {
        if(candidates[r_times].votes == candidates[j].votes)
        {
            equivalent[r_times].name = candidates[r_times].name;
            equivalent[r_times+1].name = candidates[j].name;
            r_times++;
            checker++;
        }
    }
    // print winner
    if( checker < 1)
        printf("%s\n",candidates[max_vote].name);
    
    // if case is equivalent
    else
    {
        for(int k = 0; k < candidate_count; k++)
        {
            printf("%s\n",equivalent[k].name);
        }
    }   
}