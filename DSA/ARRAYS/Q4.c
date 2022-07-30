#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);

    int A[size];
    int n, T, i, X;
    int temp;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &T);
    scanf("%d", &X);

    if (n >= size)
    {
        printf("Array is Full\n");
    }

    else
    {
        for (i = 1; i <= n; i++)
        {
            if (i == T)
            {
                temp = 1;

                break;
            }
            else
            {
                temp = 0;
            }
        }

        if (temp == 1)
        {
            n++;
            for (i = n; i > T; i--)
            {
                A[i] = A[i - 1];
            }
            A[T] = X;

            for (i = 1; i <= n; i++)
            {
                printf("%d ", A[i]);
            }
        }

        else if (temp == 0)
        {
            printf("Position Not Found\n");
        }
    }

    return 0;
}