#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to contract an edge
void contract_edge(int** adj_list, int* adj_list_size, int u, int v, int n) {
    // Merge the vertices u and v
    for (int i = 0; i < adj_list_size[v]; i++) {
        int w = adj_list[v][i];
        if (w != u) {
            adj_list[u][adj_list_size[u]++] = w;
            for (int j = 0; j < adj_list_size[w]; j++) {
                if (adj_list[w][j] == v) {
                    adj_list[w][j] = u;
                    break;
                }
            }
        }
    }
    adj_list_size[v] = 0;
    // Remove self-loops
    for (int i = 0; i < adj_list_size[u]; i++) {
        int w = adj_list[u][i];
        if (w == u) {
            for (int j = i; j < adj_list_size[u]-1; j++) {
                adj_list[u][j] = adj_list[u][j+1];
            }
            adj_list[u][adj_list_size[u]-1] = -1;
            adj_list_size[u]--;
            i--;
        }
    }
}

// Function to compute the Global Minimum Cut
int global_min_cut(int** adj_list, int* adj_list_size, int n) {
    int* contracted = (int*) calloc(n, sizeof(int));
    int num_vertices = n;
    while (num_vertices > 2) {
        // Choose a random edge to contract
        int u, v;
        do {
            u = rand() % n;
        } while (adj_list_size[u] == 0);
        v = adj_list[u][rand() % adj_list_size[u]];
        // Contract the edge (u, v)
        contract_edge(adj_list, adj_list_size, u, v, n);
        contracted[v] = 1;
        num_vertices--;
    }
    // Count the number of crossing edges
    int min_cut = 0;
    for (int i = 0; i < n; i++) {
        if (!contracted[i]) {
            for (int j = 0; j < adj_list_size[i]; j++) {
                int w = adj_list[i][j];
                if (contracted[w]) {
                    min_cut++;
                }
            }
        }
    }
    free(contracted);
    return min_cut;
}
int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    m = n*(n-1)/2; // Complete graph
    int** adj_list = (int**) calloc(n, sizeof(int*));
    int* adj_list_size = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        adj_list[i] = (int*) calloc(n, sizeof(int));
    }
    printf("Creating a complete graph with %d vertices...\n", n);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            adj_list[i][adj_list_size[i]++] = j;
            adj_list[j][adj_list_size[j]++] = i;
        }
    }
    int min_cut = global_min_cut(adj_list, adj_list_size, n);
    printf("The minimum cut is %d.\n", min_cut);
    for (int i = 0; i < n; i++) {
        free(adj_list[i]);
    }
    free(adj_list);
    free(adj_list_size);
    return 0;
}
