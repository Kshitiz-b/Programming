#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char *pat, char *txt, int q, int n, int m)
{

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
            if (j == m)
            {
                printf("The given pattern is present in the text string\n");
                printf("Total Number of shifts needed is %d \n", i);
            }
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

/* Driver Code */
int main()
{
    int i;
    int n, m;
    scanf("%d", &n);    // enter the length of the text
    scanf("%d", &m);    // enter the lenght of the pattern
    char *txt = (char *)malloc(n * sizeof(char));
    char *pat = (char *)malloc(m * sizeof(char));

    for (i = 0; i < n; i++)
    {
        scanf(" %c", txt + i);
    }
    for (i = 0; i < m; i++)
    {
        scanf(" %c", pat + i);
    }

    // A prime number
    int q = 101;

    // function call
    search(pat, txt, q, n, m);
    return 0;
}
