#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    NO,
    YES
} BOOL;

int N;
int count = 1;
int vals[100];
int wts[100];

int cap = 0;
int mval = 0;

void getWeightAndValue(BOOL incl[N], int *weight, int *value)
{
    int i, w = 0, v = 0;
    for (i = 0; i < N; ++i)
    {
        if (incl[i])
        {
            w += wts[i];
            v += vals[i];
        }
    }
    *weight = w;
    *value = v;
}

void printSubset(BOOL incl[N])
{
    int i;
    int val = 0;
    int A[N];

    // printf("Included = { ");
    for (i = 0; i < N; ++i)
    {
        if (incl[i])
        {
            // printf("1 ");
            A[i] = 1;
            val += vals[i];
        }
        else
        {
            A[i] = 0;
            // printf("0 ");
        }
    }
    count++;

    if (count > 3 && count < 5)
    {
        for (i = 0; i < N; i++)
        {

            printf("%d ", A[i]);
        }
        printf("\n");
    }
    // printf("}; Total value = %d\n", val);
}

void findKnapsack(BOOL incl[N], int i)
{
    int cwt, cval;
    getWeightAndValue(incl, &cwt, &cval);
    if (cwt <= cap)
    {
        if (cval > mval)
        {
            printSubset(incl);
            mval = cval;
        }
    }
    if (i == N || cwt >= cap)
    {
        return;
    }
    // int x = wts[i];
    BOOL use[N], nouse[N];
    memcpy(use, incl, sizeof(use));
    memcpy(nouse, incl, sizeof(nouse));
    use[i] = YES;
    nouse[i] = NO;
    findKnapsack(use, i + 1);
    findKnapsack(nouse, i + 1);
}

int main(int argc, char const *argv[])
{
    // printf("Enter the number of elements: ");
    scanf(" %d", &N);
    BOOL incl[N];
    int i;
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &vals[i]);
        incl[i] = NO;
    }
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &wts[i]);
        incl[i] = NO;
    }
    // printf("Enter knapsack capacity: ");
    scanf(" %d", &cap);
    findKnapsack(incl, 0);
    return 0;
}
