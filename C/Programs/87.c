// not showing correct output
#include <stdio.h>

int main()
{
    int m, n, i, j;
    int zerocount = 0;
    int nonzerocount = 0;
    scanf("%d %d", &m, &n);
    
    int *arr[m][n];

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d", arr[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if(arr[i][j] == 0)
            {
                zerocount += 1;
            }
            else if (arr[i][j] != 0)
            {
                nonzerocount += 1;
            }
        }
    }

    printf("Zero Count is: %d\n", zerocount);
    printf("Non Zero Count is: %d\n", nonzerocount);


    return 0;
}