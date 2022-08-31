#include <stdio.h>

void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int Partition(int A[], int n, int lb, int ub)
{
    int pivot = A[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (A[start] <= pivot)
            start++;
        while (A[end] > pivot)
            end--;

        if (start < end)
            swap(&A[start], &A[end]);
    }

    swap(&A[lb], &A[end]);
    return end;
}

void QuickSort(int A[], int n, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = Partition(A, n, lb, ub);
        QuickSort(A, n, lb, loc - 1);
        QuickSort(A, n, loc + 1, ub);
    }
}

void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int main()
{
    int n, lb, ub;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    lb = 0;
    ub = n-1;

    QuickSort(A, n, lb, ub);
    printf("The Sorted Array is:\n");
    Display(A, n);

    return 0;
}