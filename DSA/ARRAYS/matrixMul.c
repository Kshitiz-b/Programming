#include <stdio.h>

int main()
{
    int m1, n1, m2, n2, i, j, k;

    printf("Enter the size of matix A: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter the size of matix B: ");
    scanf("%d %d", &m2, &n2);

    if (n1 == m2)
    {
        int matA[m1][n1], matB[m2][n2], matC[m1][n2];

        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                scanf("%d", &matA[i][j]);
            }
        }
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                scanf("%d", &matB[i][j]);
            }
        }

        printf("Matirx A:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf("%d\t", matA[i][j]);
            }
            printf("\n");
        }
        printf("Matirx B:\n");
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                printf("%d\t", matB[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                matC[i][j] = 0;
                for (k = 0; k < n1; k++)
                {
                    matC[i][j] += matA[i][k] * matB[k][j];
                }
            }
        }
        printf("Matirx C:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                printf("%d\t", matC[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Wrong Input\n");

    return 0;
}