#include <stdio.h>

void sort(int s[], int f[], int n)
{
    int i, j, temp, flag;

    for (i = 0; i < (n - 1); i++)
    {
        flag = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (f[j] > f[j + 1])
            {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;

                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    printf("Following activities are selected\n");

    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}

int main()
{
    // int s[] = {1, 3, 0, 5, 8, 5};
    // int f[] = {2, 4, 6, 7, 9, 9};
    // int n = sizeof(s) / sizeof(s[0]);
    int n;
    scanf("%d", &n);
    int s[n], f[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
    }

    sort(s, f, n);
    printMaxActivities(s, f, n);
    return 0;
}