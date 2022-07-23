#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A;
    int size;
    int length;
    int n, i;

    printf("Enter the size of an array: ");
    scanf("%d", &size);
    A = (int *)malloc(size * sizeof(int));
    length = 0;

    printf("Enter the number of numbers: ");
    scanf("%d", &n);

    printf("Enter all elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    length = n;

    printf("The entered elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}