#include <iostream>
using namespace std;

class example
{
public:
    int a;


    example()
    {
        a = 10;
    }

    static void display(example e1)
    {
        e1.a++;
        cout << "\nThe a value in display is: " << e1.a;
    }
};

int main()
{
    // passing object as an argument to a function is similar to primitive data type
    // call-by-value

    example e1;
    example::display(e1);
    cout << "\nThe a value in main is is: " << e1.a;

    return 0;
}