// unary operator overloading
#include <iostream>
using namespace std;

class Weight
{
    int kg;

public:
    Weight()
    {
        kg = 0;
    }
    Weight(int x)
    {
        kg = x;
    }
    void print()
    {
        cout << "Weight in KG: " << kg << endl;
    }

    void operator++()
    {
        ++kg;
    }
    void operator++(int)
    {
        kg++;
    }
    void operator--()
    {
        --kg;
    }
    void operator--(int)
    {
        kg--;
    }
};

int main()
{
    Weight obj;
    obj.print();

    ++obj;
    obj.print();

    obj++;
    obj.print();

    --obj;
    obj.print();

    obj--;
    obj.print();

    

    return 0;
}