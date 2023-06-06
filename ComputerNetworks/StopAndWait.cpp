#include <iostream>
#include <string>
using namespace std;

void stopAndWait(float Tt, float Tp, int n, int loss, int A[])
{
    cout << "Max Window size (1+2a): " << 1 + 2.0 * (Tp / Tt);
    cout << "\nRequired window size: " << Tt;
    cout << "\n";

    int flag = 1, trans = 0, ack = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < loss; j++)
        {
            if (A[j] - 1 == i)
            {
                flag = 0;
                break;
            }
            else
                flag = 1;
        }
        cout << "\nSender send frame (sequence no): " << i;
        if (flag == 1)
        {
            cout << "\nAck received from receiver for frame (sequence no): " << i;
            trans++;
            ack++;
        }
        else
        {
            cout << "\nAck Not received from receiver for frame (sequence no): " << i;
            cout << "\nNow Sender Retransmitted frame: " << i;
            cout << "\nAck received from receiver for frame (sequence no): " << i;
            trans += 2;
            ack++;
        }
        cout << "\nNumber of transmissions: " << trans;
        cout << "\nNumber of acknowledgements received: " << ack;
        cout << "\n";
    }
    cout << "\nTotal Number of transmissions: " << trans;
    cout << "\nTotal Number of acknowledgements received: " << ack;
}

int main()
{
    float Tt, Tp;
    int n, loss;
    cout << "Enter Tt: ";
    cin >> Tt;
    cout << "Enter Tp: ";
    cin >> Tp;
    cout << "Enter the number of frames: ";
    cin >> n;
    cout << "How many frame loss: ";
    cin >> loss;
    cout << "Which frame loss: ";
    string A;
    cin >> A;
    int B[loss];
    B[0] = int(A[0]) - 48;
    B[1] = int(A[2]) - 48;

    stopAndWait(Tt, Tp, n, loss, B);

    return 0;
}