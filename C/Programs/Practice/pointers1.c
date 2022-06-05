#include <stdio.h>

int main()
{

    int a;
    scanf("%d", &a);
    printf("\nAddress of a is: %p\n", &a);
    printf("Value using functions: %d\n", a);
    
    int *ptr = &a;

    printf("\nAddress of pointer to a is: %p", &ptr);
    printf("\nAddress of pointer to a is: %p", ptr);
    printf("\nValue using pointer: %d", *ptr);

    return 0;
}