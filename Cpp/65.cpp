// NOT WORKING
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int z_count = 0;
    int o_count = 0;
    char letter_z = 'z';
    char letter_o = 'o';

    cin >> word;

    for (auto &elem : word)
    {
        if (elem == letter_z)
        {
            z_count += 1;
            
        }
        else if (elem == letter_o)
        {
            o_count += 1;

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
