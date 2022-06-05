#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr;
    int i, n, sum = 0;

    printf("Enter the number of values:\n");
    scanf("%d", &n);

    arr = (int *)malloc(n * (sizeof(int)));
    printf("Enter the values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + *(arr + i);
    }
    printf("The sum is %d", sum);
    
    return 0;
}