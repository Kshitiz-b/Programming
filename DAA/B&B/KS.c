#include <stdio.h>

#define MAX 100

int n, m;
int p[MAX], w[MAX];
int maxprofit, currprofit;
int include[MAX], bestset[MAX];

int promising(int i, int profit, int weight)
{
    int j, k;
    int totweight;

    if (weight >= m)
        return 0;
    else
    {
        j = i + 1;
        totweight = weight;

        while (j <= n && totweight + w[j] <= m)
        {
            totweight += w[j];
            profit += p[j];
            j++;
        }

        k = j;

        if (k <= n)
            profit += (m - totweight) * (p[k] / w[k]);

        return profit > maxprofit;
    }
}

void knapsack(int i, int profit, int weight)
{
    if (weight <= m && profit > maxprofit)
    {
        maxprofit = profit;
        for (int j = 1; j <= i; j++)
            bestset[j] = include[j];
    }

    if (promising(i, profit, weight))
    {
        include[i + 1] = 1;
        knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

        include[i + 1] = 0;
        knapsack(i + 1, profit, weight);
    }
}

int main()
{
    // printf("Enter the number of items: ");
    scanf("%d", &n);

    // printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    // printf("Enter the profits of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    // printf("Enter the weights of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    maxprofit = currprofit = 0;
    knapsack(0, 0, 0);

    // printf("Selected weights: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", bestset[i]);

    // printf("\nMax Profit: %d\n", maxprofit);

    return 0;
}
