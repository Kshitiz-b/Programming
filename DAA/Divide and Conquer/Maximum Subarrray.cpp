#include <iostream>
using namespace std;

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
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << Max_Subarray_Sum(A, n);

    return 0;
}
