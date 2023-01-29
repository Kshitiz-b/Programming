#include <stdio.h>

void Ratio(double ratio[], double wt[], double pr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ratio[i] = pr[i] / wt[i];
    }
}

void Sort(double ratio[], double wt[], double pr[], int n)
{
    int i, j, temp1, temp2, temp3;

    for (i = 0; i < (n - 1); i++)
    {
        int flag = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                temp1 = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp1;
                flag = 1;

                temp2 = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp2;
                flag = 1;

                temp3 = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp3;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void Sack(double wt[], double pr[], int n, int maxWt)
{
    double totalWt = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalWt + wt[i] <= maxWt)
        {
            totalWt += wt[i];
            profit += pr[i];
        }
        else
        {
            profit += pr[i] * ((maxWt - totalWt) / wt[i]);
            totalWt += (maxWt - totalWt) / wt[i];
            break;
        }
    }

    printf("%lf", profit);
}

int main()
{
    int n, maxWt;
    scanf("%d", &n);
    scanf("%d", &maxWt);
    double wt[n], pr[n];
    double ratio[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &pr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &wt[i]);
    }

    Ratio(ratio, wt, pr, n);
    Sort(ratio, wt, pr, n);
    Sack(wt, pr, n, maxWt);

    return 0;
}
