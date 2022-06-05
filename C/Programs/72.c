#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *a;
    int *b;
    a = (int *)malloc(1 * sizeof(int));
    b = (int *)malloc(1 * sizeof(int));
    printf("Enter the values of a and b:\n");
    scanf("%d %d", a, b);
    printf("The sum is:\n");
    printf("%d", *a + *b);

    return 0;
}