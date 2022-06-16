// Example: Find the largest of two numbers using Friend Function

#include <iostream>
using namespace std;

class Largest
{
    int a, b;
    int m;

public:
    void read();
    friend void maximum(Largest);
};

void Largest::read()
{
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
}

void maximum(Largest t)
{
    if (t.a > t.b)
    {
        t.m = t.a;
        cout << t.m;
    }
    else
    {
        t.m = t.b;
        cout << t.m;
    }
}

int main()
{
    Largest l;
    l.read();
    maximum(l);

    return 0;
}