#include <iostream>
using namespace std;
class example
{
public:
    static int a; 
    static int b; 
public:
    example(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    static void display()
    {
        cout << "\n The a and b values are: " << a << "\t" << b;
    }
};

int example::a;
int example::b;

int main()
{
    // Static member function -
    // 1. it can access only other static data or other static functions
    // 2. It can be invoked by class name using :: directly

    example e1(10, 20), e2(30, 40), e3(50, 60);

    example::display();

    return 0;
}