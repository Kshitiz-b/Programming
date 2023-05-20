#include <iostream>
#include <string>
using namespace std;

string xor_op(string a, string b)
{
    string ans = "";

    int n = b.length();

    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

string CRC_bits(string data, string crc)
{
    int len = crc.length();
    string tmp = data.substr(0, len);
    int n = data.length();

    while (len < n)
    {
        if (tmp[0] == '1')

            tmp = xor_op(crc, tmp) + data[len];
        else

            tmp = xor_op(string(len, '0'), tmp) + data[len];

        len += 1;
    }

    if (tmp[0] == '1')
        tmp = xor_op(crc, tmp);
    else
        tmp = xor_op(string(len, '0'), tmp);

    return tmp;
}

void Error_CRC(string data, string crc)
{
    int len = crc.size();
    string append = "";
    string new_data = data;
    for (int i = 0; i < len - 1; i++)
    {
        append += "0";
    }
    cout << "Number of zero's to be appended are: " << append << endl;
    new_data += append;
    cout << "Message after appending 0's: " << new_data << endl;

    string crc_bits = CRC_bits(new_data, crc);
    cout << "CRC bits: " << crc_bits << endl;

    data += crc_bits;
    cout << "Transmitted data is: " << data << endl;
}

int main()
{
    int n;
    cout << "Enter the length of data: ";
    cin >> n;
    string data;
    cout << "Enter the data: ";
    cin >> data;
    string crc;
    cout << "Enter the CRC Generator (i.e., Divisor): ";
    cin >> crc;

    Error_CRC(data, crc);

    return 0;
}