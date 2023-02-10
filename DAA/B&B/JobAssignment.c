// #include <stdio.h>
// #include <stdlib.h>
// #define N 4

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define NOT_ASSIGNED 0

int n, cost[MAX][MAX];
int l[MAX], u[MAX], x[MAX];
int path[MAX];
int minimum = INT_MAX;

void printSolution(int cost[][MAX])
{
    printf("Minimum cost: %d\n", minimum);
    printf("Job Assignment:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Worker %d assigned to job %d\n", i + 1, x[i] + 1);
    }
}

int bound(int u, int l, int x[], int cost[][MAX])
{
    int sum = u;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == NOT_ASSIGNED)
        {
            while (x[j] != NOT_ASSIGNED)
            {
                j++;
            }
            sum += cost[i][j];
        }
    }
    return sum;
}

void copySolution(int x[], int path[])
{
    for (int i = 0; i < n; i++)
    {
        path[i] = x[i];
    }
}

void jobAssignment(int u, int level, int cost[][MAX], int x[], int path[])
{
    int v;
    if (u < minimum)
    {
        if (level == n)
        {
            if (u < minimum)
            {
                minimum = u;
                copySolution(x, path);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (x[i] == NOT_ASSIGNED)
                {
                    x[i] = level;
                    v = u + cost[level][i];
                    if (v < minimum)
                    {
                        jobAssignment(v, level + 1, cost, x, path);
                    }
                    x[i] = NOT_ASSIGNED;
                }
            }
        }
    }
}

int main()
{
    printf("Enter the number of workers: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        l[i] = 0;
        u[i] = 0;
        x[i] = NOT_ASSIGNED;
        for (int j = 0; j < n; j++)
        {
            u[i] += cost[j][i];
        }
    }
    jobAssignment(0, 0, cost, x, u);
    printSolution(cost);

    return 0;
}


// int main()
// {
//         int n, m;
//         scanf("%d", &n);
//         scanf("%d", &m);

//         int A[n][m];

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 scanf("%d", &A[i][j]);
//             }
//         }

//         // for(int i=0;i<n;i++)
//         // {
//         //     for(int j=0;j<m;j++)
//         //     {
//         //         printf("%d ", A[i][j]);
//         //     }
//         //     printf("\n");
//         // }

//         return 0;
// }
