// Add a new element at the end of an array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int A[size], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    if (n <= size)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
    }
    else
    {
        printf("Array is full\n");
        for (i = 0; i < size; i++)
        {
            printf("%d ", A[i]);
        }
    }

    return 0;
}