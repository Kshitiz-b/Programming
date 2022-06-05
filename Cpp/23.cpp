#include <iostream>
using namespace std;

class example
{
    int a;

public:
    example()
    {
        a = 10;
    }

    friend void display(example e);
};

void display(example e)
{
    cout << "The a value is: " << e.a;
}

int main()
{
    // Friend functions - I gives permission to access private or protected data
    // 3 access modifiers/controls/specifiers
    // public, private, protected
    // Inheritance
    // by default is private

    example e;
    
    display(e);

    return 0;
}