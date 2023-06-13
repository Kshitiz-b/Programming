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

int to_decimal(string buffer)
{
    return stoi(buffer, 0, 2);
}

void classless(string ip)
{
    int i = 0;
    string buffer = "";
    string ip_bin = "";
    int A[4];
    int j = 0, network;

    while (i < ip.length())
    {
        if (ip[i] == '.' || ip[i] == '/')
        {
            ip_bin += to_binary(buffer);

            buffer = "";
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

    int octet;
    if (network >= 1 && network <= 8)
    {
        octet = 0;
    }
    else if (network > 8 && network <= 16)
    {
        octet = 1;
    }
    else if (network > 16 && network <= 24)
    {
        octet = 2;
    }
    else
    {
        octet = 3;
    }

    buffer = ip_bin.substr(network, 32 - network);
    for (int i = 0; i <= buffer.length(); i++)
    {
        buffer[i] = '0';
    }

    ip_bin.replace(network, 32 - network, buffer);

    ip_bin += '\0';
    buffer = "";
    int k = 0;
    while (j <= ip_bin.length())
    {
        if (j % 8 == 0 && j != 0)
        {
            A[k] = to_decimal(buffer);
            buffer = "";
            buffer += ip_bin[j];

            k++;
        }
        else
        {
            buffer += ip_bin[j];
        }
        j++;
    }

    int last_one = 8 - (network % 8);

    int max_bit = 128;
    for (int i = 1; i < last_one; i++)
    {
        max_bit -= max_bit / 2;
    }

    cout << "Starting IP: ";
    for (int i = 0; i < 4; i++)
    {
        if (i != 3)
        {
            cout << A[i] << ".";
        }
        else
        {
            cout << A[i];
        }
    }
    cout << endl;

    int B[4];
    cout << "Ending IP: ";
    for (int i = 0; i < 4; i++)
    {
        if (i >= octet)
        {
            if (i == octet)
            {
                B[i] = A[i] + max_bit - 1;
                cout << B[i] << ".";
            }
            if (i > octet)
            {
                B[i] = A[i] + 256 - 1;
                if (i != 3)
                {
                    cout << B[i] << ".";
                }
                else
                {
                    cout << B[i];
                }
            }
        }
        else
        {
            if (i != 3)
            {
                B[i] = A[i];
                cout << A[i] << ".";
            }
            else
            {
                B[i] = A[i];
                cout << A[i];
            }
        }
    }
    cout << endl;

    cout << "Lmited braodcast address: 255.255.255.255" << endl;

    cout << "Directed broadcast address: ";
    for (int i = 0; i < 4; i++)
    {
        if (i != 3)
        {
            cout << B[i] << ".";
        }
        else
        {
            cout << B[i];
        }
    }
    cout << endl;
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