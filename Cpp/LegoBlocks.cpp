#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MOD = 1000000007;

long long legoWall(int n, int m)
{
    vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, 0));

    // Initialize the base cases
    dp[0][0] = 1;

    // Fill in the dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (j >= k)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
    }

    return dp[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    long long ways = legoWall(n, m);
    cout << ways << endl;

    return 0;
}
