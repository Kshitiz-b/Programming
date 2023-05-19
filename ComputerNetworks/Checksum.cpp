#include <iostream>
#include <math.h>
using namespace std;

string add(string bin1, string bin2)
{
    string addRes;
    int len, carry, re, i;

    len = bin1.size();
    addRes = "";
    carry = 0;
    for (i = (len - 1); i > -1; i--)
    {
        re = carry;
        if (bin1[i] == '1')
            re = re + 1;
        else
            re = re + 0;
        if (bin2[i] == '1')
            re = re + 1;
        else
            re = re + 0;
        if (re % 2 == 1)
            addRes = '1' + addRes;
        else
            addRes = '0' + addRes;
        if (re < 2)
            carry = 0;
        else
            carry = 1;
    }
    if (carry != 0)
        addRes = '1' + addRes;
    return addRes;
}

void checksum(string bin[], int n, int m)
{
    string addRes="";
    for(int i=0;i<n;i++)
    {
        addRes = add(bin[i], addRes);
    }

    cout << "Total Sum: " << addRes << endl;
}

int main()
{
    int n, m;
    cout << "Enter number of frames: ";
    cin >> n;
    cout << "Enter each frame size: ";
    cin >> m;
    string bin[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter frame " << i+1 << ": ";
        cin >> bin[i];
    }

    checksum(bin, n, m);
}
