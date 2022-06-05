// function overloading
#include <iostream>
using namespace std;

class master
{
public:

    void func(int x)
    {
        cout  << "The value of func is: " << x << endl;
    }

    void func(double x)
    {
        cout << "The value of func is: " << x << endl;
    }

    void func(float x, float y)
    {
        cout << "The value of func is: " << x << ", " << y << endl;
    }

};

int main()
{
    master m1;
    m1.func(5);
    m1.func(2.5468);
    m1.func(5.2, 4.98);

    return 0;
}