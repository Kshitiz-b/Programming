#include <stdio.h>

void MagicSquare(int n)
{
    int ms[n][n], num;

    memset(ms, 0, sizeof(ms));

    int i = n / 2;
    int j = n - 1;

    for (num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (i < 0)
                i = n - 1;

            if (j == n)
                j = 0;
        }
        if (ms[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            ms[i][j] = num++;

        j++;
        i--;
    }

    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n", n, n * (n * n + 1) / 2);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d ", ms[i][j]);
        printf("\n");
    }
}

int main()
{
    int a;
    printf("Enter the odd number: ");
    scanf("%d", &a);
    MagicSquare(a);
}