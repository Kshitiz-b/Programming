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

    if (A[0] >= 0 && A[0] <= 127)
    {
        // cout << "IP Address belongs to class: " << "A" << endl;
        //  cout << "Network IP Address: " << A[0] << ".0.0.0" << endl;
        //  cout << "Direct Broadcast Address: " << A[0] << ".255.255.255" << endl;
        //  cout << "Limited Broadcast Address = 255.255.255.255" << endl;
    }
    else if (A[0] >= 128 && A[0] <= 191)
    {

        // cout << "IP Address belongs to class: " << "B" << endl;
        //  cout << " IP Address: " << A[0] << "." << A[1] << ".0.0" << endl;
        //  cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << ".255.255" << endl;
        //  cout << "Limited Broadcast Address = 255.255.255.255";
    }
    else if (A[0] >= 192 && A[0] <= 223)
    {
        // cout << "IP Address belongs to class: " << "C" << endl;
        //  cout << "Network IP Address: " << A[0] << "." << A[1] << "." << A[2] << ".0" << endl;
        //  cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << "." << A[2] << ".255" << endl;
        //  cout << "Limited Broadcast Address = 255.255.255.255";
    }
    else if (A[0] >= 224 && A[0] <= 239)
    {
        // cout << "IP Address belongs to class: " << "D" << endl;
        //  cout << "Network IP Address: Not available" << endl;
        //  cout << "Direct Broadcast Address: Not available" << endl;
        //  cout << "Limited Broadcast Address: Not available" << endl;
    }
    else if (A[0] >= 240 && A[0] <= 255)
    {
        // cout << "IP Address belongs to class: " << "E" << endl;
        //  cout << "Network IP Address: Not available" << endl;
        //  cout << "Direct Broadcast Address: Not available" << endl;
        //  cout << "Limited Broadcast Address: Not available" << endl;
    }
    else
    {
        cout << "not a valid IP Address" << endl;
    }
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