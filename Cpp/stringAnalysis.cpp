#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

void checkString(string str)
{
    int n = str.length();
    int u = 0, l = 0, d = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        if (isupper(str[i]))
            u++;
        else if (islower(str[i]))
            l++;
        else if (isdigit(str[i]))
            d++;
        else
            o++;
    }
    cout << fixed << setprecision(3) << (double(u) / double(n)) * 100 << "%" << endl;
    cout << fixed << setprecision(3) << (double(l) / double(n)) * 100 << "%" << endl;
    cout << fixed << setprecision(3) << (double(d) / double(n)) * 100 << "%" << endl;
    cout << fixed << setprecision(3) << (double(o) / double(n)) * 100 << "%" << endl;
}

int main()
{
    string str;
    cin >> str;
    checkString(str);

    return 0;
}