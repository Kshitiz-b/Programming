#include <iostream>
#include <cstdio>
using namespace std;

int findMinimumSetSize(int num, int k)
{
    if (num == 0)
    {
        return 0; // If num is 0, an empty set is valid.
    }

    if (k == 0)
    {
        return -1; // Cannot have a unit digit of 0 in any positive integer.
    }

    if (num % 10 == k)
    {
        return 1; // If num is already a single integer with unit digit k, return 1.
    }

    // Try to find the minimum size of the set.
    for (int i = 2; i <= 10; i++)
    {
        int remaining = num - i * k;
        if (remaining >= 0 && remaining % 10 == 0)
        {
            return i; // Found a valid set of size i.
        }
    }

    return -1; // No valid set found.
}

int main()
{
    int num, k;
    cin >> num >> k;

    int result = findMinimumSetSize(num, k);
    cout << result << endl;

    return 0;
}
