#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);

    int A[size];
    int n, T, i, X, index;
    int temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &T);
    scanf("%d", &X);

    if (n > size)
    {
        printf("Array is Full\n");
    }

    else
    {
        for (i = 0; i < n; i++)
        {
            if (A[i] == T)
            {
                temp = 1;
                index = i;
                break;
            }
            else
            {
                temp = 0;
            }
        }
    }

    if (temp == 1)
    {
        for (i = n; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = X;
        n++;
    }
    else if (temp == 0)
    {
        printf("Target Element Not Found\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}