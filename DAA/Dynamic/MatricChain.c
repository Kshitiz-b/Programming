#include <stdio.h>
#define maxSize 100

int Matrix(int p[], int n)
{
    int m[maxSize][maxSize];
    int i, j, L, k, q;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = 999;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n];
}

int main()
{
    int n;
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("ANS: %d", Matrix(p, n - 1));

    return 0;
}