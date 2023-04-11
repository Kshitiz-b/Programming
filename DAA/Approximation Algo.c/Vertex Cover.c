#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

int adj_list[MAX_VERTICES][MAX_VERTICES]; // adjacency list to store graph
bool visited[MAX_VERTICES];               // to keep track of visited vertices

// function to add an edge to the graph
void add_edge(int u, int v)
{
    adj_list[u][v] = 1;
    adj_list[v][u] = 1;
}

// function to find the vertex cover of the graph
void vertex_cover(int v, int e)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            // if vertex i is not visited, visit its neighbors
            for (j = 0; j < v; j++)
            {
                if (adj_list[i][j] == 1 && !visited[j])
                {
                    visited[i] = true;
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    // print the vertex cover
    printf("Vertex Cover: ");
    for (i = 0; i < v; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int v, e, i, u, v;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &v, &e);
    for (i = 0; i < e; i++)
    {
        printf("Enter the edge (u, v): ");
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    vertex_cover(v, e);
    return 0;
}
