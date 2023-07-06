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
    int B[4];
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

    string startip = ip_bin.substr(network, 32 - network);
    string endip = ip_bin.substr(network, 32 - network);
    for (int i = 0; i <= startip.length(); i++)
    {
        startip[i] = '0';
    }
    for (int i = 0; i <= endip.length(); i++)
    {
        endip[i] = '1';
    }

    ip_bin.replace(network, 32 - network, startip);
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

    ip_bin.replace(network, 32 - network, endip);
    buffer = "";
    j = 0;
    k = 0;
    while (j <= ip_bin.length())
    {
        if (j % 8 == 0 && j != 0)
        {
            B[k] = to_decimal(buffer);
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

    cout << "Ending IP: ";
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

    cout << "KSHITIZ BHARGAVA - 21BCE2067\n";

    classless(ip);

    return 0;
}