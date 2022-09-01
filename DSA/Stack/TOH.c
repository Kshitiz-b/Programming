#include <stdio.h>

void TOH(int A, int B, int C, int n)
{
    if (n > 0)
    {
        TOH(A, C, B, n - 1);
        printf("Move a disc from %d to %d\n", A, C);
        TOH(B, A, C, n - 1);
    }
}

int main()
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int A = 1, B = 2, C = 3;
    TOH(A, B, C, n);

    return 0;
}