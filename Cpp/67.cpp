#include <iostream>
using namespace std;

class B;

class A
{
public:
    int x;

    void read()
    {
        cout << "Enter x: ";
        cin >> x;
    }

    friend void largest(A, B);
};

class B
{
public:
    int y;

    void read()
    {
        cout << "Enter y: ";
        cin >> y;
    }

    friend void largest(A, B);
};

void largest(A t1, B t2)
{
    if (t1.x > t2.y)
    {
        cout << "Largest no is: " << t1.x;
    }
    else
    {
        cout << "Largest no is: " << t2.y;
    }
}

int main()
{
    A a;
    B b;
    a.read();
    b.read();

    largest(a, b);

    return 0;
}