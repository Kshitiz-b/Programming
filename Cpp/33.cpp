#include <iostream>
using namespace std;

class sample
{
public:
    void display()
    {
        cout << "This is a function without arguments\n";
    }

    void display(int a)
    {
        cout << "This is a function with one argument\n";
    }

    void display(int a, int b)
    {
        cout << "This is a function with two arguments\n";
    }

    void display(double a, double b)
    {
        cout << "This is a function with two double arguments\n";
    }
};

int main()
{
    sample s;
    s.display(34.5, 23.45);
    s.display();
    s.display(78);
    s.display(2, 3);

    return 0;
}