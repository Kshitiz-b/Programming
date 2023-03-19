// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Write C code here
    int n = 4;
    printf("Hello world\n");
    char A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &A[i][j]);
        }
    }
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 'I')
                graph[i][j] = 9999;
            else
                graph[i][j] = A[i][j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}