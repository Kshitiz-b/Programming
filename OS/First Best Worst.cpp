// First Fit, Best Fit, Worst Fit
#include <iostream>

using namespace std;

int main()
{
    int block[10], process[10], b, p, i, j, flag[10], allocation[10];
    for (i = 0; i < 10; i++)
    {
        flag[i] = 0;
        allocation[i] = -1;
    }
    cout << "Enter no. of blocks: ";
    cin >> b;
    cout << "Enter size of each block: ";
    for (i = 0; i < b; i++)
        cin >> block[i];
    cout << "Enter no. of processes: ";
    cin >> p;
    cout << "Enter size of each process: ";
    for (i = 0; i < p; i++)
        cin >> process[i];
    for (i = 0; i < p; i++)
        for (j = 0; j < b; j++)
            if (flag[j] == 0 && block[j] >= process[i])
            {
                allocation[j] = i;
                flag[j] = 1;
                break;
            }
    cout << "\nBlock no.\tBlock size\tProcess no.\tProcess size\tFragment";
    for (i = 0; i < b; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << block[i] << "\t\t";
        if (flag[i] == 1)
            cout << allocation[i] + 1 << "\t\t" << process[allocation[i]] << "\t\t" << block[i] - process[allocation[i]];
        else
            cout << "Not allocated";
    }
    return 0;
}