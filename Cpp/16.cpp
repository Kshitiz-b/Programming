#include<iostream>
using namespace std;

class example
{
    int a;
    int b;

    public:
    example(int n1, int n2)
    {
        a = n1;
        b = n2;

    }

    void display()
    {
        cout << "\nThe a and b values are: " << a << "   " << b;
    }
};

int main()
{
    // static vs. non-static data members
    example e1(10, 20), e2(30, 40), e3(50, 60);

    e1.display();
    e2.display();
    e3.display();

    return 0;
}