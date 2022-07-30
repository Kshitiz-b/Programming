#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    scanf("%d", &size);

    int A[size], n, i, index = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Forward:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nBackward:");
    for (i = n - 1; i >= index; i--)
    {
        printf("%d ", A[i]);
    }

    return 0;
}