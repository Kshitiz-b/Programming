#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Subsequence(string str, string subse, int index)
{
    if (index == str.length())
    {
        if (!subse.empty())
        {
            if (subse.length() == 2)
                cout << subse << " ";
        }
        return;
    }

    Subsequence(str, subse + str[index], index + 1);
    Subsequence(str, subse, index + 1);
}

void spec(string str)
{
    string pre = "", suff = "", substr = "", subse = "";
    int size = str.length();
    int i;

    cout << "Prefix: ";
    for (i = 0; i < size; i++)
    {
        pre += str[i];
        cout << pre << " ";
    }

    cout << endl
         << "Suffix: ";
    for (i = 0; i <= size; i++)
    {
        suff = "";
        for (int j = size - i; j < size; j++)
        {
            suff += str[j];
        }
        cout << suff << " ";
    }

    cout << endl
         << "Substring: ";
    for (i = 0; i < size; i++)
    {
        substr = "";
        for (int j = 1; j <= size - i; j++)
        {
            substr = str.substr(i, j);
            cout << substr << " ";
        }
    }

    cout << endl
         << "Subsequence: ";

    Subsequence(str, subse, 0);
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    spec(str);

    return 0;
}