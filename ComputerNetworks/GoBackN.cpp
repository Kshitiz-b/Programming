#include <iostream>
#include <string>
using namespace std;

void goBackN(float Tt, float Tp, int n, int frames, int A[])
{
    cout << "Max Window size (1+2a): " << 1 + 2.0 * (Tp / Tt);
    cout << "\nRequired window size: " << n;
    cout << "\n";
    int i = 0;
    int j = n;
    int trans = 0, ack = 0;
    int flag = 1, index, flag1 = 1;
    string re = "";
    while (i < frames && j <= frames)
    {
        if (i != 0)
        {
            cout << "\nNow Sender Window contains: ";
        }
        else
        {
            cout << "\nSender window contains: ";
            trans += 4;
        }
        for (int k = j - 1; k >= i; k--)
        {
            cout << k;
            re += (char)k + 48;
        }

        for (int k = i; k < j; k++)
        {
            if (A[0] - 1 != k)
            {
                flag = 1;
                index = k;
                break;
            }
            else
            {
                flag = 0;
                index = k;
                break;
            }
        }
        cout << "\nTill Transmited data=" << trans;
        cout << "\nTill Acknowledged data=" << ack;

        if (flag == 1)
        {
            if (j != frames)
            {
                cout << "\nAck received from receiver for frame (sequence no): " << index;
                trans++;
                ack++;
            }
            else
            {
                cout << "\nAck received from receiver for frame (sequence no): " << index;
                ack++;
            }
            flag1 = 1;
        }
        else
        {
            cout << "\nAck Not received from receiver for frame (sequence no): " << index;
            flag1 = 0;
            trans += 4;
            ack++;
        }
        if (flag1 == 0)
        {
            cout << "\n\nNow Sender window contains (retranmit all in window): ";
            for (int i = re.size() - 4; i < re.size(); i++)
                cout << re[i];
            cout << "\nTill Transmited data=" << trans;

            cout << "\nTill Acknowledged data=" << ack;

            cout << "\nAck received from receiver for frame (sequence no): " << index;
            ack++;
            index--;
        }

        i++;
        if (j != frames)
        {
            j++;
        }
        cout << "\n";
    }
    cout << "\nTotal Transmission: " << trans;
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

    goBackN(Tt, Tp, n, frames, A);

    return 0;
}