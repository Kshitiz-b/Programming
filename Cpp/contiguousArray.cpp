#include <iostream>
#include <cstdio>
using namespace std;

int contiguousArray(int n, int A[])
{
    int max = 0, count = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i] == 0)
        {
            count++;
        }
        else
        {
            if(count > max)
            {
                max = count;
            }
            count = 0;
        }
    }
    if(count > max)
    {
        max = count;
    }
    return max*2;
} 

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    int ans = contiguousArray(n, A);
    cout << ans << endl;

    return 0;
}