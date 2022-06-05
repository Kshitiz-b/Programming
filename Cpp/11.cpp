#include<iostream>
using namespace std;

class complex
{
    private:
    int real;
    int imag;

    public:
    void readdata()
    {
        cout << "\nEnter real and imaginary values:\n";
        cin >> real >> imag;
    }

    void displaydata()
    {
        cout << "The Complex Number is:\n";
        cout << real << " + i" << imag;
    }
};


int main()
{
    complex c1;
    c1.readdata();
    c1.displaydata();

    complex c2;
    c2.readdata();
    c2.displaydata();

    return 0;
}