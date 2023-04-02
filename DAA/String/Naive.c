#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define n 16
#define m 4

void search(char *txt, char *pat)
{
    int i, j, count = 0, temp = 0, ans;
    printf("Pattern found at ");

    for (i = 0; i <= n - m; i++)
    {
        temp++;
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] == pat[j])
                count++;
        }
        if (count == m)
        {
            if (temp - 1 != 12)
            {
                ans = temp - 1;
                printf("%d ", ans);
            }
            else
            {
                ans = temp - 1;
                printf("and %d", ans);
            }
        }
        count = 0;
    }
}

int main()
{
    int i;
    // int n = 10, m = 3;
    //  scanf("%d", &n);
    //  scanf("%d", &m);
    char *txt, *pat;

    txt = (char *)malloc(n * sizeof(char));
    pat = (char *)malloc(m * sizeof(char));

    for (i = 0; i < n; i++)
    {
        scanf(" %c", txt + i);
    }
    for (i = 0; i < m; i++)
    {
        scanf(" %c", pat + i);
    }

    search(txt, pat);
}
