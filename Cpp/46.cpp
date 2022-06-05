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

    Weight operator++()
    {
        Weight temp;
        temp.kg = ++kg;
        return temp;
    }

    Weight operator++(int)
    {
        Weight temp1;
        temp1.kg = kg++;
        return temp1;
    }

    Weight operator--()
    {
        Weight temp2;
        temp2.kg = kg--;
        return temp2;
    }

    Weight operator--(int)
    {
        Weight temp3;
        temp3.kg = --kg;
        return temp3;
    }
};

int main()
{
    Weight obj1, obj2;
    obj2 = ++obj1;
    obj2.print();
    
    obj2 = obj1--;
    obj2.print();

    obj2 = obj1++;
    obj2.print();

    obj2 = --obj1;
    obj2.print();

    return 0;
}