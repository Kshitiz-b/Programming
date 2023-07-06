#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int to_int(string buffer)
{
    return stoi(buffer);
}

void classful(string ip, int sub, int first)
{
    cout << ip << " is a classful format of ";
    char class_ip;
    if (first < 128)
    {
        class_ip = 'A';
        cout << "Class: " << class_ip << endl;
    }
    else if (first < 192)
    {
        class_ip = 'B';
        cout << "Class: " << class_ip << endl;
    }
    else if (first < 224)
    {
        class_ip = 'C';
        cout << "Class: " << class_ip << endl;
    }
    else if (first < 240)
    {
        class_ip = 'D';
        cout << "Class: " << class_ip << endl;
    }
    else if (first < 256)
    {
        class_ip = 'E';
        cout << "Class: " << class_ip << endl;
    }
    else
    {
        cout << "Invalid IP" << endl;
    }
    ip += '\0';
    int A[4], j = 0, i = 0;
    string buffer = "";
    while (ip[i] != '\0')
    {
        if (ip[i] == '.')
        {
            A[j] = to_int(buffer);
            buffer = "";
            j++;
        }
        else
        {
            buffer += ip[i];
        }
        i++;
    }

    A[4] = 0;
    if (sub % 2 == 0)
    {
        for (int i = 0; i < sub; i++)
        {
            cout << i + 1 << " Subnet:" << endl;
            cout << "ip address of the subnet: ";
            long long int total_hosts;
            if (class_ip == 'A')
            {
                total_hosts = pow(2, 24);
                cout << A[0] << ".0.0.0" << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            else if (class_ip == 'B')
            {
                total_hosts = pow(2, 16);
                cout << A[0] << "." << A[1] << ".0.0" << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            else if (class_ip == 'C')
            {
                total_hosts = pow(2, 8);
                cout << A[0] << "." << A[1] << "." << A[2] << "." << A[4] << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
                cout << "Range of IP Addresses:\n";
                cout << "St IP: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] << endl;
                cout << "End IP: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] + 256 / sub - 1 << endl;
                cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] + 256 / sub - 1 << endl;
                A[4] += 256 / sub;
            }
            else
            {
                total_hosts = pow(2, 0);
                cout << A[0] << "." << A[1] << "." << A[2] << "." << A[3] << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            cout << "Limited Broadcast Address: 255.255.255.255" << endl;
        }
    }
    else
    {
        int j = -1;
        for (int i = 0; i < sub; i++)
        {
            cout << i + 1 << " Subnet:" << endl;
            cout << "ip address of the subnet: ";
            long long int total_hosts;
            if (class_ip == 'A')
            {
                total_hosts = pow(2, 24);
                cout << A[0] << ".0.0.0" << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            else if (class_ip == 'B')
            {
                total_hosts = pow(2, 16);
                cout << A[0] << "." << A[1] << ".0.0" << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            else if (class_ip == 'C')
            {
                total_hosts = pow(2, 8);
                cout << A[0] << "." << A[1] << "." << A[2] << "." << A[4] << endl;
                cout << "Total number of IP Addresses: " << 256 / (sub + j) << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / (sub + j) - 2 << endl;
                cout << "Range of IP Addresses:\n";
                cout << "St IP: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] << endl;
                cout << "End IP: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] + 256 / (sub + j) - 1 << endl;
                cout << "Direct Broadcast Address: " << A[0] << "." << A[1] << "." << A[2] << "." << A[4] + 256 / (sub + j) - 1 << endl;
                A[4] += 256 / (sub + j);
                j = 1;
            }
            else
            {
                total_hosts = pow(2, 0);
                cout << A[0] << "." << A[1] << "." << A[2] << "." << A[3] << endl;
                cout << "Total number of IP Addresses: " << 256 / sub << endl;
                cout << "Total number of hosts that can be configured: " << total_hosts / sub - 2 << endl;
            }
            cout << "Limited Broadcast Address: 255.255.255.255" << endl;
        }
    }
}

void classless(string ip, int sub)
{
    cout << ip << " is a classless format" << endl;
}

int main()
{
    string ip;
    int sub;
    cout << "IP address: ";
    cin >> ip;
    cout << "Enter Number of subnets: ";
    cin >> sub;

    cout << "Kshitiz Bhargava - 21BCE2067\n";

    string buffer = "";
    int i = 0;
    while (ip[i] != '.')
    {
        buffer += ip[i];
        i++;
    }
    int first = to_int(buffer);
    int len = ip.length();
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (ip[i] == '/')
        {
            flag = 1;
        }
    }

    if (flag == 0)
        classful(ip, sub, first);
    else
        classless(ip, sub);

    return 0;
}