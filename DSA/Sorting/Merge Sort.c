#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);

        merge(A, l, mid, r);
    }
}

void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Before Sorting\n");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("After Sorting\n");
    printArray(A, n);
    return 0;
}
