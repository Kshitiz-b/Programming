#include <stdio.h>

void InsertionSort(int A[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
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
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    InsertionSort(A, n);
    printf("The Sorted Array is:\n");
    Display(A, n);

    return 0;
}