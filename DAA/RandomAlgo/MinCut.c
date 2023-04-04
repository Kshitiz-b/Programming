#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Finds the global minimum cut of the given graph with n vertices and adjacency matrix graph
int global_minimum_cut(int n, int **graph)
{
    // Allocate memory for the vertex labels
    int *labels = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        labels[i] = i;
    }

    // Contract the vertices until only 2 are left
    while (n > 2)
    {
        // Generate a random edge
        int u = rand() % n;
        int v = rand() % n;
        while (labels[u] != labels[v])
        {
            if (graph[u][v] && rand() % 2 == 0)
            {
                break;
            }
            v = rand() % n;
        }

        // Contract the edge
        for (int i = 0; i < n; i++)
        {
            graph[labels[u]][i] += graph[labels[v]][i];
            graph[i][labels[u]] += graph[i][labels[v]];
        }
        labels[labels[v]] = labels[u];
        n--;
    }

    // Count the cut
    int cut = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j])
            {
                cut += graph[i][j];
            }
        }
    }

    // Free the memory allocated for the vertex labels
    free(labels);

    // Return the cut
    return cut;
}

int main()
{
    int n = 4;
    int adj[n][n];

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j > 0)
            {
                adj[i][j] = 1;
            }
            else if (i == 1 && (j == 3 || j == 0))
            {
                adj[i][j] = 1;
            }
            else if (i == 2 && j == 3)
            {
                adj[i][j] = 1;
            }
            else if (i == 3 && j == 0)
            {
                adj[i][j] = 1;
            }
            else
            {
                adj[i][j] = 0;
            }
        }
    }

    // Allocate memory for the graph
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    // Copy the adjacency matrix to the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = adj[i][j];
        }
    }

    // Find the contraction edges
    printf("The contraction edges are:\n");
    srand(time(NULL));
    while (n > 2)
    {
        int cut = global_minimum_cut(n, graph);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] && rand() % (n - 1) < cut)
                {
                    printf("(%d,%d)\n", i, j);
                    for (int k = 0; k < n; k++)
                    {
                        graph[i][k] += graph[j][k];
                        graph[k][i] += graph[k][j];
                    }
                    graph[j][j] = 0;
                    n--;
                }
            }
        }
        printf("The cut found by the randomized algorithm is: %d\n", cut);
    }

    // Find the cut found
    int cut = global_minimum_cut(n, graph);
    // printf("The cut found by the randomized algorithm is: %d\n", cut);

    // Free the memory allocated for the graph
    for (int i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}