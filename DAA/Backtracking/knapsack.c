#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

struct Item
{
    int value;
    int weight;
    float bound;
};

int n, maxWeight;
struct Item items[MAX_ITEMS];

int cmp(const void *a, const void *b)
{
    return ((struct Item *)b)->bound - ((struct Item *)a)->bound;
}

int promising(int i, int weight, int totalValue)
{
    if (weight >= maxWeight)
    {
        return 0;
    }
    int j, k;
    int totweight;
    float bound = totalValue;
    j = i + 1;
    totweight = weight;
    while ((j < n) && (totweight + items[j].weight <= maxWeight))
    {
        totweight += items[j].weight;
        bound += items[j].value;
        j++;
    }
    k = j;
    if (k < n)
    {
        bound += (maxWeight - totweight) * items[k].value / items[k].weight;
    }
    return bound > totalValue;
}

void knapsack(int i, int weight, int totalValue)
{
    int t;
    if (weight <= maxWeight && totalValue > items[0].value)
    {
        items[0].value = totalValue;
    }
    if (promising(i, weight, totalValue))
    {
        t = weight + items[i + 1].weight;
        if (t <= maxWeight)
        {
            knapsack(i + 1, t, totalValue + items[i + 1].value);
        }
        knapsack(i + 1, weight, totalValue);
    }
}

int main()
{
    int i, totvalue = 0;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of knapsack: ");
    scanf("%d", &maxWeight);
    for (i = 0; i < n; i++)
    {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d%d", &items[i].value, &items[i].weight);
        items[i].bound = (float)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(struct Item), cmp);
    items[0].value = 0;
    knapsack(0, 0, 0);
    printf("The maximum value of knapsack is %d\n", items[0].value);
    return 0;
}
