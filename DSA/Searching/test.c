#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    char A[50][50];
    char X[50];
    int n;
    int i, j = 0, flag = 0, index;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", &A[i]);
    }
    scanf("%s", &X);

    for (i = 0; i < n; i++)
    {
        j = strcmp(A[i], X);
        if (j == 0)
        {
            flag = 1;
            index = i+1;
        }
    }
    if (flag == 1)
    {
        printf("Found at index %d", index);
    }
    else
    {
        printf("Not Found");
    }

    return 0;
}