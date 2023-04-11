#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000       // maximum number of candidates
#define MAX_RATING 100 // maximum rating of a candidate

typedef struct
{
    int rating; // rating of the candidate
    int hired;  // whether the candidate is hired
} Candidate;

// Function to generate random integer in the range [a, b]
int randInt(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

// Function to initialize the candidates with random ratings
void initCandidates(Candidate candidates[], int n)
{
    for (int i = 0; i < n; i++)
    {
        candidates[i].rating = randInt(1, MAX_RATING);
        candidates[i].hired = 0;
    }
}

// Function to print the ratings of the candidates
void printCandidates(Candidate candidates[], int n)
{
    printf("Candidate ratings: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", candidates[i].rating);
    }
    printf("\n");
}

// Function to find the best candidate using the hiring algorithm
int findBestCandidate(Candidate candidates[], int n)
{
    int best = -1;
    for (int i = 0; i < n; i++)
    {
        if (!candidates[i].hired && (best == -1 || candidates[i].rating > candidates[best].rating))
        {
            best = i;
        }
    }
    candidates[best].hired = 1;
    return best;
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    int n;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    Candidate candidates[N];
    initCandidates(candidates, n);
    printCandidates(candidates, n);
    int k;
    printf("Enter the number of candidates to hire: ");
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int best = findBestCandidate(candidates, n);
        printf("Hired candidate %d with rating %d\n", best + 1, candidates[best].rating);
    }
    return 0;
}
