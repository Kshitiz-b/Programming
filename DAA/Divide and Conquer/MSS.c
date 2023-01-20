#include <stdio.h>
#define INT_MIN -999

int max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

int Max_Subarray_Sum(int A[], int n)
{
    if (n == 1)
        return A[0];
    int m = n / 2;
    int LSS = Max_Subarray_Sum(A, m);
    int RSS = Max_Subarray_Sum(A + m, n - m);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;
    for (int i = m; i < n; i++)
    {
        sum += A[i];
        rightsum = max(rightsum, sum);
    }
    sum = 0;
    for (int i = (m - 1); i >= 0; i--)
    {
        sum += A[i];
        leftsum = max(leftsum, sum);
    }
    int ans = max(LSS, RSS);
    return max(ans, leftsum + rightsum);
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Maximum subarray sum = %d", Max_Subarray_Sum(A, n));

    return 0;
}
