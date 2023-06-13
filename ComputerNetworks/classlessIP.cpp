#include <iostream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;

void classless(string ip)
{
    int i = 0;
    string buffer = "";
    int A[4];
    int j = 0, network;

    while (i < ip.length())
    {
        if (ip[i] == '.' || ip[i] == '/')
        {
            A[j] = stoi(buffer);
            buffer = "";
            j++;
        }
        else if (ip[i] == '\0')
        {
            network = stoi(buffer);
            buffer = "";
        }
        else
        {
            buffer += ip[i];
        }
        i++;
    }

    cout << "Reserved bits for Network: " << network << endl;
    cout << "Reserved bits for Host: " << 32 - network << endl;
    long int total_hosts = pow(2, 32 - network);
    cout << "Total number of hosts in that network: " << total_hosts << endl;

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != 0)
        {
            buffer += '.';
        }
        for (int k = 0; k < 8; k++)
        {
            if (count != network)
            {
                buffer += '1';
                count++;
            }
            else
            {
                buffer += '0';
            }
        }
    }

    cout << "The Default Subnet Mask: " << buffer << endl;
    int octet;
    if (network >= 1 && network <= 8)
    {
        octet = 1;
    }
    else if (network > 8 && network <= 16)
    {
        octet = 2;
    }
    else if (network > 16 && network <= 24)
    {
        octet = 3;
    }
    else
    {
        octet = 4;
    }
    int last_one = 8 - (network % 8);

    int max_bit = 128;
    for (int i = 1; i < last_one; i++)
    {
        max_bit -= max_bit / 2;
    }
    cout << "Subnet Generator Bit: " << max_bit << endl;
    cout << "Octet: " << octet << endl;
}

int main()
{
    string ip;
    cin >> ip;
    ip += '\0';

    // cout << "KSHITIZ BHARGAVA - 21BCE2067\n";

    classless(ip);

    return 0;
}