#include <iostream>
using namespace std;

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

int main()
{
    // Module 7 - Polymorphosis
    // An entity ehich behaves differently in different scenarios
    // in C++ - entity - a function or an operator
    // two types of polymorphosis
    // Function overloading 
    // function behaves differently in different context 

    display(34.5, 23.45);
    display();
    display(78);
    display(2, 3);

    return 0;
}