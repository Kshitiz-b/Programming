#include <iostream>
#include <string>
using namespace std;

string complement(string str)
{
    int len = str.length();
    string result = "";

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '1')
            result += '0';
        else if (str[i] == '0')
            result += '1';
    }

    return result;
}

string add(string a, string b)
{
    string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;
    while (size_a >= 0 || size_b >= 0 || temp == 1)
    {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--;
        size_b--;
    }
    return result;
}

void checksum(string bin[], int n, int m)
{
    string addRes = "";
    string tmp1 = "", tmp2 = "";
    for (int i = 0; i < n; i++)
    {
        addRes = add(bin[i], addRes);
    }

    // cout << addRes << endl;

    int len = addRes.length();
    if (len > m)
    {
        for (int i = 0; i < len - m; i++)
        {
            tmp1 += addRes[i];
        }
        // cout << tmp1 << endl;
        for (int i = len - m; i < len; i++)
        {
            // cout << addRes[i] << " ";
            tmp2 += addRes[i];
        }
        // cout << endl << tmp2 << endl;
        addRes = add(tmp1, tmp2);
    }

    cout << "Total Sum: " << addRes << endl;
    string check = complement(addRes);
    cout << "Checksum: " << check << endl;

    cout << "Sent Message: ";
    for (int i = 0; i < n; i++)
    {
        cout << bin[i];
    }
    cout << check;
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
        cout << "Enter frame " << i + 1 << ": ";
        cin >> bin[i];
    }

    checksum(bin, n, m);
}
