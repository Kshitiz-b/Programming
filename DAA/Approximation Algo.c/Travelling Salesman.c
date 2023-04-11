#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int n;                  // number of cities
int dist[MAX_N][MAX_N]; // distance matrix
int path[MAX_N];        // path array to store the current path
int visited[MAX_N];     // to keep track of visited cities
int min_dist = INT_MAX; // to store the minimum distance found so far
int min_path[MAX_N];    // to store the minimum path found so far

// recursive function to generate all possible paths
void tsp(int curr_city, int curr_dist, int curr_path[])
{
    int i;
    // base case: if all cities have been visited
    if (curr_city == n)
    {
        // check if the current path is shorter than the minimum path found so far
        if (curr_dist + dist[curr_path[curr_city - 1]][0] < min_dist)
        {
            min_dist = curr_dist + dist[curr_path[curr_city - 1]][0];
            for (i = 0; i < n; i++)
            {
                min_path[i] = curr_path[i];
            }
            min_path[n] = 0;
        }
        return;
    }
    // recursive case: visit all unvisited cities
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            curr_path[curr_city] = i;
            tsp(curr_city + 1, curr_dist + dist[curr_path[curr_city - 1]][i], curr_path);
            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }
    visited[0] = 1; // start with city 0
    path[0] = 0;
    tsp(1, 0, path); // generate all possible paths starting from city 0
    printf("Minimum distance: %d\n", min_dist);
    printf("Minimum path: ");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", min_path[i]);
    }
    printf("\n");
    return 0;
}
