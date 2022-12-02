#include <stdio.h>

int BinarySearch(int A[], int n, int X, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == X)
            return mid;
        else if (X > A[mid])
            return BinarySearch(A, n, X, mid + 1, r);
        else
            return BinarySearch(A, n, X, l, mid - 1);
    }
    return -1;
}

int main()
{
    int n, index;
    printf("Enter n: ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int X;
    printf("Enter X: ");
    scanf("%d", &X);

    index = BinarySearch(A, n, X, 0, n - 1);
    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element found at %d\n", index+1);
    return 0;
}