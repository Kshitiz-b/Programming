#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void SelectionSort(int A[], int n)
{
    int i, j, minIdx;

    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (A[j] < A[minIdx])
                minIdx = j;

        if (minIdx != i)
            swap(&A[minIdx], &A[i]);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    SelectionSort(A, n);
    display(A, n);

    return 0;
}