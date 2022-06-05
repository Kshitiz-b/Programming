#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Mutiple integer values - Two dimentional array

    int *p;
    int m, n, i, j;

    printf("\n Enter row size: ");
    scanf("%d", &m);

    printf("\n Enter column size: ");
    scanf("%d", &n);

    p = (int *)malloc((m * n) * sizeof(int));

    printf("\n Enter %d values: \n", m * n);

    int *temp;
    temp = p;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", p);
            p++;
        }
    }

    printf("\n Entered values are: \n");
    p = temp;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", *p);
            p++;
        }
        printf("\n");
    }

    p = temp;
    free(p);

    return 0;
}