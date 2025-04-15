#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9
typedef struct
{
    char *name;
    int votes;
} candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void divided(candidate uns[], int start, int end);
void marge(candidate uns[], int start, int end, int med);
void find_winnre(int max_vote, int s);
int main(int argc, string argv[])
{   
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1; }
    
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2; }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int start = 0, end = candidate_count -1 ,s = 0; 
    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
            printf("Invalid vote.\n");
    }
    divided(candidates, start, end);
    find_winnre(candidates[0].votes, s);
}
bool vote(string name)
{
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
void divided(candidate uns[], int start, int end)
{
    int med = (start + end) /2;
    if(start >= end)
        return;
    divided(uns, start, med);
    divided(uns, med+1, end);

    marge(uns, start, end, med);
}
void marge(candidate uns[], int start, int end, int med)
{
    int lsize = med - start + 1;
    int rsize = end - med;
   
    candidate *lside = malloc(lsize * sizeof(candidate));
    candidate *rside = malloc(rsize * sizeof(candidate));
    if (lside == NULL || rside == NULL)
    {
        printf("Memory allocation failed.\n"); 
        exit(1);
    }

    for(int i = 0; i < lsize; i++)
        lside[i] = uns[start+i];
    for(int j = 0; j < rsize; j++)
        rside[j] = uns[med+1+j];

    int i = 0, j = 0, k = start;
    while (i < lsize && j < rsize)
    {
        if (lside[i].votes >= rside[j].votes)
            uns[k++] = lside[i++];
        else
            uns[k++] = rside[j++];
    }

    while (i < lsize)
        uns[k++] = lside[i++];

    while (j < rsize)
        uns[k++] = rside[j++];

    free(lside);
    free(rside);    
}


void find_winnre (int max_vote, int s)
{   
    if(candidates[s+1].votes < max_vote)
        printf("Winner is %s, %i\n", candidates[s].name, candidates[s].votes);
    //liner search
    else
    {
        find_winnre(max_vote, s+1);
            printf("Winner is %s, %i\n", candidates[s].name, candidates[s].votes);
    }
}


