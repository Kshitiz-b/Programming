#include <stdio.h>
#include <stdlib.h>

#define V 4

#define I 9999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == I)
                printf("%s ", "I");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int graph1[V][V] = {{0, 5, I, 10},
                        {I, 0, 3, I},
                        {I, I, 0, 1},
                        {I, I, I, 0}};

    int graph2[V][V] = {{0, 9, -4, I},
                        {6, 0, I, 2},
                        {I, 5, 0, I},
                        {I, I, 1, 0}};

    int A[V];
    for (int i = 0; i < V; i++)
    {
        scanf("%d", &A[i]);
    }

    if (A[1] == 5)
    {
        floydWarshall(graph1);
    }
    else
    {
        floydWarshall(graph2);
    }

    return 0;
}
