#include <stdio.h>
#include <string.h>

void computeLPS(char *pattern, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (pattern[i])
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *string, char *pattern)
{
    int n = strlen(string);
    int m = strlen(pattern);
    int lps[m];
    computeLPS(pattern, lps);
    int i = 0, j = 0, shift = 0;
    while (i < n)
    {
        if (pattern[j] == string[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            printf("The given pattern is found in the string\nTotal number of shifts took place for the match is %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != string[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        shift++;
    }
    //printf("Number of shifts needed to find the match: %d\n", shift);
}

int main()
{
    char string[100], pattern[100];
    //printf("Enter the string: ");
    scanf("%s", string);
    //printf("Enter the pattern: ");
    scanf("%s", pattern);
    KMP(string, pattern);
    return 0;
}