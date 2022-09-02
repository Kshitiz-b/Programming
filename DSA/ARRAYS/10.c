// Inserting after a target element
// Inserting an element before a target element
#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int A[size], i, n, T, X, temp, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &T);

    printf("Enter the element: ");
    scanf("%d", &X);

    for (i = 0; i < n; i++)
    {
        if (A[i] == T)
        {
            temp = 1;
            index = i+1;
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
        for (i = n; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = X;
        
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