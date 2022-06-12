//NOT WORKING
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string word;
    int z_count = 0;
    int o_count = 0;
    string letter_z;
    string letter_o;

    letter_z = "z";
    letter_o = "o";

    cin >> word;

    for (int i = 0; i < 10; i++)
    {
        if (word[i] == letter_z)
        {
            z_count = z_count + 1;
        }
        else if (word[i] == letter_o)
        {
            o_count = o_count + 1;
        }
    }

    if ((z_count * 2) == o_count)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
