#include <stdio.h>

int sum(int a, int b)
{
    printf("Enter a, b: \n");
    scanf("%d %d", &a, &b);
    return a + b;
}

int main(void)
{

    int a, b, c;
    c = sum(a, b);
    printf("%d", c);

    return 0;
}