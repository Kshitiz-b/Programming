#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    scanf("%d", &size);

    int a[size];
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    if (n <= size)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else if (n > size)
    {
        printf("Array is Full\n");

        for (i = 0; i < size; i++)
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}