#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 20

int i, j, m, n, LCS_table[20][20];
char b[20][20];

void lcsAlgo(char S1[], char S2[])
{
    m = strlen(S1);
    n = strlen(S2);

    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            }
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j];
            }
            else
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }

    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS IS: %s", lcsAlgo);
}

int main()
{
    char S1[20], S2[20];
    fgets(S1, MAX_LIMIT, stdin);
    fgets(S2, MAX_LIMIT, stdin);

    lcsAlgo(S1, S2);

    return 0;
}
