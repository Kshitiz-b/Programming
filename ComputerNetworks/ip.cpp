#include <iostream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;

string to_binary(string buffer)
{
    string temp = "";
    int dec = stoi(buffer);
    bitset<8> bin(dec);
    return bin.to_string();
}

void classes(string ip_dec)
{
    int k = 0, i = 0;
    string buffer = "";
    int A[4];
    while (k < ip_dec.length())
    {
        if (ip_dec[k] == '.' || ip_dec[i] == '\0')
        {
            if (i < 4)
            {
                A[i] = stoi(buffer);
                i++;
                buffer = "";
            }
        }
        else
        {
            buffer += ip_dec[k];
        }
        k++;
    }

    if (A[0] >= 0 && A[0] <= 127)
    {
        cout << "IP Address belongs to class: "
             << "A" << endl;
        cout << "Network IP Address: " << A[0] << ".0.0.0" << endl;
        cout << "Direct Broadcast Address: " << A[0] << ".255.255.255" << endl;
        cout << "Limited Broadcast Address = 255.255.255.255" << endl;
    }
    else if (A[0] >= 128 && A[0] <= 191)
    {

        cout << "IP Address belongs to class: "
             << "B" << endl;
        cout << "Network IP Address: " << A[0] << "." << A[1] << ".0.0" << endl;
        cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << ".255.255" << endl;
        cout << "Limited Broadcast Address = 255.255.255.255";
    }
    else if (A[0] >= 192 && A[0] <= 223)
    {
        cout << "IP Address belongs to class: "
             << "C" << endl;
        cout << "Network IP Address: " << A[0] << "." << A[1] << "." << A[2] << ".0" << endl;
        cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << "." << A[2] << ".255" << endl;
        cout << "Limited Broadcast Address = 255.255.255.255";
    }
    else if (A[0] >= 224 && A[0] <= 239)
    {
        cout << "IP Address belongs to class: "
             << "D" << endl;
        cout << "Network IP Address: Not available" << endl;
        cout << "Direct Broadcast Address: Not available" << endl;
        cout << "Limited Broadcast Address: Not available" << endl;
    }
    else if (A[0] >= 240 && A[0] <= 255)
    {
        cout << "IP Address belongs to class: "
             << "E" << endl;
        cout << "Network IP Address: Not available" << endl;
        cout << "Direct Broadcast Address: Not available" << endl;
        cout << "Limited Broadcast Address: Not available" << endl;
    }
    else
    {
        cout << "not a valid IP Address" << endl;
    }
}

int main()
{
    string ip_dec;
    cin >> ip_dec;
    ip_dec += '\0';

    cout << "KSHITIZ BHARGAVA - 21BCE2067\n";

    classes(ip_dec);

    return 0;
}