// Practice using templates
#include <iostream>
using namespace std;

template <class T>

class master
{
public:
    T *ptr;

    T a, b;
    void read(T x, T y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "OUTPUT1: " << a << endl;
        cout << "OUTPUT2: " << b << endl << endl;
    }
};

int main()
{
    master<int> m1;
    m1.read(4, 5);
    m1.display();

    master<float> m2;
    m2.read(2.5, 6.9);
    m2.display();

    return 0;
}