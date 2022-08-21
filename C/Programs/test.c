#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, a[50], size;
    printf("Enter the size of an array\n");
    scanf("%d", &size);

    printf("Enter the elements of the array\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The elements are:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}