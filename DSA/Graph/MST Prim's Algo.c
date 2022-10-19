/* Program for creating minimum spanning tree from Prim's algorithm */
#include <stdio.h>
#include <conio.h>
#define MAX 10
#define TEMP 0
#define PERM 1
#define FALSE 0
#define TRUE 1
#define infinity 9999
struct node
{
    int predecessor;
    int dist; /*Distance from predecessor */
    int status;
};
struct edge
{
    int u;
    int v;
};
int adj[MAX][MAX];
int n;
int create_graph()
{
    int i, max_edges, origin, destin, wt;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    max_edges = n * (n - 1) / 2;
    for (i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d(0 0 to quit) : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        printf("Enter weight for this edge : ");
        scanf("%d", &wt);
        if (origin > n || destin > n || origin <= 0 ||
            destin <= 0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = wt;
            adj[destin][origin] = wt;
        }
    }
    return 0;
}
int all_perm(struct node state[MAX])
{
    int i;
    for (i = 1; i <= n; i++)
        if (state[i].status == TEMP)
            return FALSE;
    return TRUE;
}
int display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%3d", adj[i][j]);
        printf("\n");
    }
    return 0;
}
int maketree(struct edge tree[MAX], int *weight)
{
    struct node state[MAX];
    int i, min, count, current;
    // int m;
    int u1, v1;
    *weight = 0;
    for (i = 1; i <= n; i++)
    {
        state[i].predecessor = 0;
        state[i].dist = infinity;
        state[i].status = TEMP;
    }
    state[1].predecessor = 0;
    state[1].dist = 0;
    state[1].status = PERM;

    current = 1;
    count = 0;
    while (all_perm(state) != TRUE)
    {
        for (i = 1; i <= n; i++)
            if (adj[current][i] > 0 && state[i].status == TEMP)
                if (adj[current][i] < state[i].dist)
                {
                    state[i].predecessor = current;
                    state[i].dist = adj[current][i];
                }
        min = infinity;
        for (i = 1; i <= n; i++)
            if (state[i].status == TEMP && state[i].dist < min)
            {
                min = state[i].dist;
                current = i;
            }
        state[current].status = PERM;
        u1 = state[current].predecessor;
        v1 = current;
        count++;
        tree[count].u = u1;
        tree[count].v = v1;
        *weight = *weight + adj[u1][v1];
    }
    return (count);
}
int main()
{
    int i;
    // int path[MAX];
    int wt_tree, count;
    struct edge tree[MAX];
    // clrscr();
    create_graph();
    printf("Adjacency matrix is :\n");
    display();
    count = maketree(tree, &wt_tree);
    printf("Weight of spanning tree is : %d\n", wt_tree);
    printf("Edges to be included in spanning tree are : \n");
    for (i = 1; i <= count; i++)
    {
        printf("%d->", tree[i].u);
        printf("%d\n", tree[i].v);
    }
    return 0;
}
