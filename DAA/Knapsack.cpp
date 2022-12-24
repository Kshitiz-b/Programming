#include <iostream>
using namespace std;

class Knapsack
{
public:
    void Ratio(int ratio[], int wt[], int pr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            ratio[i] = pr[i] / wt[i];
        }
    }

    void Sort(int ratio[], int wt[], int pr[], int n)
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

    void Sack(int wt[], int pr[], int n, int maxWt)
    {
        int totalWt = 0, profit = 0, curr_profit, index;
        for (int i = 0; i < n; i++)
        {
            if (totalWt + wt[i] <= maxWt)
            {
                totalWt += wt[i];
                profit += pr[i];
            }
            else
            {
                curr_profit = pr[i] * (double(maxWt - totalWt) / wt[i]);
                pr[i] = curr_profit;
                wt[i] = (maxWt - totalWt);
                totalWt += wt[i];
                profit += curr_profit;
                
                if(totalWt == maxWt)
                {
                    index = i;
                    
                }
            }
        }

        for (int i = 0; i <= index && wt[i]!=0; i++)
        {
            cout << wt[i] << " " << pr[i] << endl;
        }

        cout << profit << endl;
    }
};

int main()
{
    int n, maxWt;
    cin >> n;
    int wt[n], pr[n], ratio[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i];
    }
    cin >> maxWt;

    Knapsack k1;
    k1.Ratio(ratio, wt, pr, n);
    k1.Sort(ratio, wt, pr, n);
    k1.Sack(wt, pr, n, maxWt);

    return 0;
}