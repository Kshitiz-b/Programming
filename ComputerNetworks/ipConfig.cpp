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
    int k=0;
    string buffer="";
    while (ip_dec[k] != '.')
    {
        buffer += ip_dec[k];
        k++;
    }
    int firstbyte = stoi(buffer);

    //string total_bits = "";

    if(firstbyte >= 0 && firstbyte <= 127)
    {
        long long int total_bits = pow(2,31);
        long long int host = pow(2,24);
        long long int net = pow(2,7);
        cout << "IP address class information: " << "A" << endl;
        cout << "Total IP addresses possible in that class: " << total_bits << endl;
        cout << "Possible host: " << host << endl;
        cout << "Possible Networks: " << net << endl;
        cout << "StratIP: 0.x.x.x" << endl;
        cout << "EndIP: 127.x.x.x" << endl;
    }
    else if(firstbyte >= 128 && firstbyte <= 191)
    {
        long long int total_bits = pow(2,30);
        long long int host = pow(2,16);
        long long int net = pow(2,14);
        cout << "IP address class information: "  << "B" << endl;
        cout << "Total IP addresses possible in that class: " << total_bits << endl;
        cout << "Possible host: " << host << endl;
        cout << "Possible Networks: " << net << endl;
        cout << "StratIP: 128.0.x.x" << endl;
        cout << "EndIP: 191.255.x.x" << endl;
    }
    else if(firstbyte >= 192 && firstbyte <= 223)
    {
        long long int total_bits = pow(2,29);
        long long int host = pow(2,8);
        long long int net = pow(2,21);
        cout << "IP address class information: "  << "C" << endl;
        cout << "Total IP addresses possible in that class: " << total_bits << endl;
        cout << "Possible host: " << host << endl;
        cout << "Possible Networks: " << net << endl;
        cout << "StratIP: 192.0.0.x" << endl;
        cout << "EndIP: 223.255.255.x" << endl;
    }
    else if(firstbyte >= 224 && firstbyte <= 239)
    {
        cout << "IP address class information: "  << "D" << endl;
    }
    else if(firstbyte >= 240 && firstbyte <= 225)
    {
        cout << "IP address class information: "  << "E" << endl;
    }
    else
    {
        cout << "IP address class information: "  << "Invalid IP" << endl;
    }
}

int main()
{
    string ip_dec;
    //cout << "Enter the IP Address: ";
    cin >> ip_dec;
    ip_dec += '\0';

    cout << "KSHITIZ BHARGAVA - 21BCE2067\n";
    string ip_bin = "";
    string buffer = "";
    int count = 0;
    for (int i = 0; i < ip_dec.length(); i++)
    {
        if (ip_dec[i] == '.' || ip_dec[i] == '\0')
        {
            ip_bin += to_binary(buffer);
            if (count < 3)
            {
                ip_bin += '.';
                count++;
            }
            buffer = "";
        }
        else
        {
            buffer += ip_dec[i];
        }
    }

    cout << ip_bin << endl;

    classes(ip_dec);

    return 0;
}