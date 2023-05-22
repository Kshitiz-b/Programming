#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char parity(char d1, char d2, char d3)
{
    int count = 0;
    if (d1 == '1')
        count++;
    if (d2 == '1')
        count++;
    if (d3 == '1')
        count++;

    if (count % 2 != 0)
        return '1';
    else
        return '0';
}

char parity(char d1, char d2, char d3, char d4, char d5)
{
    int count = 0;
    if (d1 == '1')
        count++;
    if (d2 == '1')
        count++;
    if (d3 == '1')
        count++;
    if (d4 == '1')
        count++;
    if (d5 == '1')
        count++;

    if (count % 2 != 0)
        return '1';
    else
        return '0';
}

void reverseArray(char arr[], int start, int end)
{
    while (start < end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Hamming(int n, string message)
{
    int power = 1, r = 0;

    while (power < (n + r + 1))
    {
        r++;
        power *= 2;
    }

    int redundancyBits = r;
    cout << "Redundancy Bits: " << redundancyBits << endl;

    int totalBits = n + redundancyBits;
    cout << "Total Bits: " << totalBits << endl;

    char hammingCode[totalBits];
    hammingCode[totalBits] = '\0';

    for (int i = 0; i < totalBits; i++)
    {
        hammingCode[i] = 'G';
    }
    for (int c = 0; c < totalBits; c++)
    {
        int i = pow(2, c);
        if (i < totalBits)
            hammingCode[i - 1] = 'P';
    }
    reverseArray(hammingCode, 0, totalBits - 1);

    int index = 0;
    for (int i = 0; i < totalBits; i++)
    {
        if (hammingCode[i] == 'G')
        {
            hammingCode[i] = message[index];
            index++;
        }
    }

    int count = 0;
    for (int i = totalBits - 1; i >= 0; i--)
    {
        if (hammingCode[i] == 'P')
        {
            if (totalBits == 7)
            {
                if (count == 0)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[2], hammingCode[4]);
                }
                else if (count == 1)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[1], hammingCode[4]);
                }
                else if (count == 2)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[1], hammingCode[2]);
                }
                else
                    continue;
            }
            else if (totalBits == 11)
            {
                if (count == 0)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[2], hammingCode[4], hammingCode[6], hammingCode[8]);
                }
                else if (count == 1)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[1], hammingCode[4], hammingCode[5], hammingCode[8]);
                }
                else if (count == 2)
                {
                    hammingCode[i] = parity(hammingCode[4], hammingCode[5], hammingCode[6]);
                }
                else if (count == 3)
                {
                    hammingCode[i] = parity(hammingCode[0], hammingCode[1], hammingCode[2]);
                }
                else
                    continue;
            }

            count++;
        }
    }

    cout << hammingCode << endl;
}

int main()
{
    int n;
    cout << "Enter message length: ";
    cin >> n;

    string message;
    cout << "Enter message bits: ";
    cin >> message;

    Hamming(n, message);

    return 0;
}