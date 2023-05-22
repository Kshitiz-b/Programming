#include <iostream>
#include <string>
#include <math.h>
using namespace std;

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
    int redundancyBits = n - 1;
    cout << "Redundancy Bits: " << redundancyBits << endl;

    int totalBits = n + redundancyBits;
    cout << "Total Bits: " << totalBits << endl;

    char hammingCode[totalBits];

    for (int i = 0; i < totalBits; i++)
    {
        hammingCode[i] = 'G';
    }
    for (int i = 0; i < totalBits; i = pow(2, i))
    {
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

    int count=0;
    for(int i=totalBits-1;i>=0;i++)
    {
        if(hammingCode[i] == 'P')
        {
            if(count == 0)
            {
                hammingCode[i] = 
            }
            else if(count == 1)
            {

            }
            else if(count == 2)
            {

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