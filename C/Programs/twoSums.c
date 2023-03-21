#include <stdio.h>

void twoSums(int n, int nums[], int target)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                printf("[%d,%d]", i, j);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int target;
    scanf("%d", &target);

    twoSums(n, nums, target);

    return 0;
}