#include <stdio.h>
#include <limits.h>

#define N 4
#define M 4

int row[N], col[M];
int matrix[N][M];

void print(int result[])
{
    int i;
    for (i = 0; i < M; ++i)
        printf("W%d - J%d \n", result[i] + 1, i + 1);
    printf("\n");
}

int findCost()
{
    int i, j, cost = 0, min;
    for (i = 0; i < N; ++i)
    {
        min = INT_MAX;
        for (j = 0; j < M; ++j)
            if (matrix[i][j] < min)
                min = matrix[i][j];
        cost += min;
    }
    return cost;
}

void branchAndBound(int level, int result[], int bound)
{
    int i, cost;
    if (level == M)
    {
        cost = findCost();
        if (cost < bound)
        {
            bound = cost;
            print(result);
        }
        return;
    }
    for (i = 0; i < N; ++i)
    {
        if (row[i] || col[level])
            continue;
        result[level] = i;
        row[i] = 1;
        col[level] = 1;
        branchAndBound(level + 1, result, bound);
        row[i] = 0;
        col[level] = 0;
    }
}

int main()
{
    int i, j, result[M];
    printf("Enter the time taken to complete the jobs by the workers:\n");
    for (i = 0; i < N; ++i)
        for (j = 0; j < M; ++j)
            scanf("%d", &matrix[i][j]);
    for (i = 0; i < M; ++i)
        row[i] = col[i] = 0;
    printf("The optimal job assignments are:\n");
    branchAndBound(0, result, INT_MAX);
    return 0;
}
