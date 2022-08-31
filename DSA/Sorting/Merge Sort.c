// Not Working
#include <stdio.h>

void Merge(int A[], int mid, int lb, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int B[k];

    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}

void MergeSort(int A[], int n, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        MergeSort(A, n, lb, mid);
        MergeSort(A, n, mid + 1, ub);

        Merge(A, mid, lb, ub);
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
    ub = n - 1;

    MergeSort(A, n, lb, ub);
    printf("The Sorted Array is:\n");
    Display(A, n);

    return 0;
}