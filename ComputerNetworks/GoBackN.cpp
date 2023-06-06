#include <iostream>
#include <queue>
using namespace std;

void goBackN(float Tt, float Tp, int n, int frames, int loss, int A[])
{
    cout << "Max Window size (1+2a): " << 1 + 2.0 * (Tp / Tt);
    cout << "\nRequired window size: " << n;
    cout << "\n";
    // int c = frames-n;

    // for(int i=0;i<frames-n+1;i++)
    // {
    //     for(int j=i;j<frames-c;j++)
    //     {
    //         cout << j <<" ";
    //     }
    //     c--;
    // }
    // int B[frames];
    // for(int i=0;i<frames;i++)
    // {
    //     B[i] = i;
    // }
    int c=n, x=0;
    for(int i=c-1;i>=x && x!=frames;i--)
    {
        cout << i << " ";
        c++;
        x++;
    }
}

int main()
{
    float Tt, Tp;
    int n, frames, loss;
    cout << "Enter Tt: ";
    cin >> Tt;
    cout << "Enter Tp: ";
    cin >> Tp;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << "How many frame loss: ";
    cin >> loss;
    int A[loss];
    cout << "Which frame loss: ";
    for (int i = 0; i < loss; i++)
    {
        cin >> A[i];
    }

    goBackN(Tt, Tp, n, frames, loss, A);

    return 0;
}