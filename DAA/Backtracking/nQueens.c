#include <stdio.h>
#include <stdbool.h>

void printSolution(int n, int A[n][n])
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    for (int i = 0; i < n; i++)
    {
        // printf("(");
        printf("(%d,", i + 1);
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                printf("%d", j + 1);
            }
        }
        printf(")");
    }
}

bool isSafe(int n, int A[n][n], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (A[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (A[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (A[i][j])
            return false;

    return true;
}

bool solveNQUtil(int n, int A[n][n], int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col >= n)
        return true;

    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < n; i++)
    {
        /* Check if the queen can be placed on
        A[i][col] */
        if (isSafe(n, A, i, col))
        {
            /* Place this queen in A[i][col] */
            A[i][col] = 1;

            /* recur to place rest of the queens */
            if (solveNQUtil(n, A, col + 1))

                return true;

            /* If placing queen in A[i][col]
            doesn't lead to a solution, then
            remove queen from A[i][col] */
            A[i][col] = 0; // BACKTRACK
        }
    }

    /* If the queen cannot be placed in any row in
        this column col then return false */
    return false;
}

void solveNQ(int n, int A[n][n])
{
    for (int i = 0; i < n; i++)
    {
        if (solveNQUtil(n, A, i) == true)
        {
            printSolution(n, A);
        }
        else
        {
            printf("\nSolution does not exist\n");
        }
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
    }

    solveNQ(n, A);
    // print(n, A);

    return 0;
}
