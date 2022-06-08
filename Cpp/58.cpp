#include <iostream>
using namespace std;

template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T1, class T2>

float funcAvg(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

int main()
{
    float a;
    a = funcAvg(5, 2);
    cout << "\nThe avg of the numbers is " << a << endl;

    int x = 5, y = 7;
    swapp(x, y);
    cout << "Now x is: " <<  x << endl << "Now y is: " <<  y;

    return 0;
}