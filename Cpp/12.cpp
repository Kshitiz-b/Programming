#include <iostream>
using namespace std;

class complex
{
private:
    float real;
    float imag;

public:
    complex(float v1, float v2)
    {
        real = v1;
        imag = v2;
    }

    void displaydata()
    {

        cout << real << " + " << imag << "i\n";
    }
};

int main()
{
    complex c1(2.0, 3.0);
    c1.displaydata();

    complex c2(5.0, 9.0);
    c2.displaydata();

    return 0;
}