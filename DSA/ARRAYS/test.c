#include <stdio.h>
#include <stdlib.h>

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void insertion(int A[], int n)
{
    int T, X;
    scanf("%d", &T);
    scanf("%d", &X);

    if (T > n)
        printf("Position Not Found\n");
    else
    {
        for (int i = n; i >= T; i--)
        {
            A[i] = A[i - 1];
        }
        A[T - 1] = X;
        n++;
    }

    display(A, n);
}

int main()
{
    int max, n, i;
    scanf("%d", &max);
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    if (n >= max)
    {
        printf("Array is Full\n");
    }
    else
        insertion(A, n);

    return 0;
}