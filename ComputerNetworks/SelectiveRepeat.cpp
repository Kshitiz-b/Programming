#include <iostream>
#include <string>
using namespace std;

void selectiveRepeat(float Tt, float Tp, int n, int frames, int loss, int A[])
{
    int size = 1 + 2.0 * (Tp / Tt);
    cout << "Max Window size (1+2a): " << size;
    cout << "\nRequired window size: " << size;
    cout << "\n";

    int flag = 1, trans = 0, ack = 0;
    int c = frames - n;
    int flag1 = 1, index;
    for (int i = c - n; i < c && c <= frames; i += n)
    {
        for (int j = i; j < c; j++)
        {
            for (int k = 0; k < loss; k++)
            {
                if (A[k] - 1 == j)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nAck received from receiver for frame (sequence no): " << j;
                flag1 = 1;
                trans++;
                ack++;
            }
            else
            {
                cout << "\nAck Not received from receiver for frame (sequence no): " << j;
                flag1 = 0;
                index = j;
                trans++;
            }
            if (flag1 == 0)
            {
                cout << "\nNow Sender Retransmitted frame: " << index;
                trans++;
                ack++;
            }
        }
        c += n;
        cout << "\n";
        cout << "\nNumber of transmissions: " << trans;
        cout << "\nNumber of acknowledgements received: " << ack;
    }
}

int main()
{
    float Tt, Tp;
    int n, loss, frames;
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
    string A;
    cin >> A;
    int B[loss];
    B[0] = int(A[0]) - 48;
    B[1] = int(A[2]) - 48;

    selectiveRepeat(Tt, Tp, n, frames, loss, B);

    return 0;
}