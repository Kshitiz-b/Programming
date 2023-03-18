#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define d 256

void search(char *pat, char *txt, int q, int n, int m)
{

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == m)
            {
                printf("The given pattern is present in the text string\n");
                printf("Total Number of shifts needed is %d \n", i);
            }
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char txt[20], pat[20];

    scanf("%[^\n]%*c", txt);
    scanf("%[^\n]%*c", pat);

    int n = strlen(txt);
    int m = strlen(pat);
    int q = 101;

    search(pat, txt, q, n, m);
    return 0;
}
