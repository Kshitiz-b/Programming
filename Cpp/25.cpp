#include <iostream>
using namespace std;

class A
{
    int a;

public:
    A()
    {
        a=12;
    }

    friend class B;
};

class B
{
public:
    void display(A e)
    {
        cout << "The calss A data member value is: " <<  e.a;
    }
};

int main()
{

    A aobj;
    
    B bobj;
    bobj.display(aobj);

    return 0;
}