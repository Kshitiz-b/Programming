#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct
{
    int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
    int flow[MAX_NODES][MAX_NODES];     // flow matrix
    int parent[MAX_NODES];              // parent array for BFS
    int visited[MAX_NODES];             // visited array for BFS
} Graph;

void initialize(Graph *G)
{
    memset(G->capacity, 0, sizeof(G->capacity));
    memset(G->flow, 0, sizeof(G->flow));
}

int dfs(Graph *G, int source, int sink)
{
    int queue[MAX_NODES], front = 0, rear = 0;
    memset(G->visited, 0, sizeof(G->visited));
    memset(G->parent, -1, sizeof(G->parent));
    queue[rear++] = source;
    G->visited[source] = 1;
    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 0; v < MAX_NODES; v++)
        {
            if (!G->visited[v] && G->capacity[u][v] > G->flow[u][v])
            {
                G->visited[v] = 1;
                G->parent[v] = u;
                queue[rear++] = v;
            }
        }
    }
    return G->visited[sink];
}

int max_flow(Graph *G, int source, int sink)
{
    int u, v, max_flow = 0;
    while (dfs(G, source, sink))
    {
        int path_flow = INT_MAX;
        for (v = sink; v != source; v = G->parent[v])
        {
            u = G->parent[v];
            path_flow = path_flow < G->capacity[u][v] - G->flow[u][v] ? path_flow : G->capacity[u][v] - G->flow[u][v];
        }
        for (v = sink; v != source; v = G->parent[v])
        {
            u = G->parent[v];
            G->flow[u][v] += path_flow;
            G->flow[v][u] -= path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    Graph G;
    initialize(&G);
    G.capacity[0][1] = 11;
    G.capacity[0][2] = 12;
    G.capacity[1][3] = 12;
    G.capacity[2][1] = 1;
    G.capacity[2][4] = 11;
    G.capacity[3][5] = 19;
    G.capacity[4][3] = 7;
    G.capacity[4][5] = 4;
    
    printf("The maximum flow in the graph is %d\n", max_flow(&G, 0, 5));
    return 0;
}
