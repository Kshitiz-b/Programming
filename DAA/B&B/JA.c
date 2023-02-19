#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int n, m;                // n: number of workers, m: number of jobs
int cost[MAX][MAX];      // cost matrix to store the time taken by each worker to complete each job
int assigned[MAX];       // to keep track of assigned jobs
int best_time = INT_MAX; // to store the minimum time required to complete all the jobs

void printSolution(int *assignment)
{
    // printf("\nWorker\t Job\t Time");
    for (int i = 0; i < n; i++)
    {
        printf("W%d-J%d", i + 1, assignment[i] + 1);
        printf("\n");
    }
}

int computeCost(int *assignment)
{
    int total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        total_cost += cost[i][assignment[i]];
    }
    return total_cost;
}

void branchAndBound(int depth, int *assignment)
{
    if (depth == n)
    { // all jobs have been assigned
        int current_time = computeCost(assignment);
        if (current_time < best_time)
        {
            best_time = current_time;
            for (int i = 0; i < n; i++)
            {
                assigned[i] = assignment[i];
            }
        }
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (assignment[i] == -1)
        { // job is unassigned
            assignment[i] = depth;
            branchAndBound(depth + 1, assignment);
            assignment[i] = -1; // undo the assignment
        }
    }
}

int main()
{
    // printf("Enter the number of workers: ");
    scanf("%d", &n);
    // printf("Enter the number of jobs: ");
    scanf("%d", &m);
    // printf("Enter the time taken by each worker to complete each job:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    int assignment[MAX];
    for (int i = 0; i < m; i++)
    {
        assignment[i] = -1; // initialize to unassigned
    }
    branchAndBound(0, assignment);
    printSolution(assigned);
    printf("%d", best_time);
    return 0;
}
