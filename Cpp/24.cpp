#include <iostream>
using namespace std;

class complex
{
    int real;
    int imag;

public:
    complex()
    {
        real = 3;
        imag = 2;
    }

    friend void addition(complex e1, complex e2);
};

void addition(complex e1, complex e2)
{
    complex temp;
    temp.real = e1.real + e2.real;
    temp.imag = e1.imag + e2.imag;
    cout << temp.real << temp.imag;
}

int main()
{

    complex c1, c2;

    addition(c1, c2);

    return 0;
}