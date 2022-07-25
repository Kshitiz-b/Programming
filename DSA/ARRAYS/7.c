//  Deleting an element
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int A[size], i, n, X, temp, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the Target element: ");
    scanf("%d", &X);

    for (i = 0; i < n; i++)
    {
        if (A[i] == X)
        {
            printf("Element is present\n");
            temp = 1;
            index = i;
            break;
        }
        else
        {
            temp = 0;
        }
    }

    if (temp == 1)
    {
        for (i = index - 1; i < n - 1; i++)
        {
            A[i] = A[i + 1];
        }
        n--;
        printf("%d is deleted\n", X);
    }

    else if (temp == 0)
    {
        printf("Target Element not found\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}