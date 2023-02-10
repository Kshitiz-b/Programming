#include <stdio.h>
#include <math.h>
#define INT_MAX 999

int mincost;

void takeInput(int n, int costMatrix[n][n])
{
    int i, j;
    // printf("Enter the Tcost matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }
}

void printAssigned()
{
    //int i;
    // printf("The assigned jobs are: \n");
    // for (i = 0; i < n; i++)
    // {
    //     printf("Worker %d is assigned to job %d\n", i + 1, assigned[i] + 1);
    // }
    printf("%d\n", mincost + 1);
}

int findUnassignedJob(int n, int assigned[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (assigned[i] == -1)
        {
            return i;
        }
    }
    return -1;
}

int isValid(int job, int n, int assigned[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (assigned[i] == job)
        {
            return 0;
        }
    }
    return 1;
}

int calcCost(int n, int assigned[n], int costMatrix[n][n])
{
    int i, Tcost = 0;
    for (i = 0; i < n; i++)
    {
        Tcost += costMatrix[i][assigned[i]];
    }
    return Tcost;
}

void updateMinCost(int Tcost)
{
    if (Tcost < mincost)
    {
        mincost = Tcost;
    }
}

void backtrack(int n, int cost[n][n], int assigned[n], int worker, int costSoFar, int costMatrix[n][n])
{
    int job;
    if (worker == n)
    {
        updateMinCost(costSoFar);
    }
    else
    {
        for (job = 0; job < n; job++)
        {
            if (isValid(job, n, assigned))
            {
                assigned[worker] = job;
                backtrack(n, cost, assigned, worker + 1, costSoFar + costMatrix[worker][job], costMatrix);
                assigned[worker] = -1;
            }
        }
    }
}

void jobAssignment(int n, int assigned[n], int costMatrix[n][n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        assigned[i] = -1;
    }
    mincost = INT_MAX;
    backtrack(n, costMatrix, assigned, 0, 0, costMatrix);
}

int main()
{

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int costMatrix[n][n];
    int assigned[n];

    takeInput(n, costMatrix);
    jobAssignment(n, assigned, costMatrix);
    printAssigned();
    return 0;
}
