#include<iostream>
using namespace std;

class example
{
    int a;

    public:
    example(int a)
    {
        this -> a = a;  // this pointer variable - LHS 'a' refers to current object data member
        
    }
    
    void display()
    {
        cout << "\nThe a value is: " << a;
    }
};

int main()
{
    // this pointer - pointer variable which refers current object 

    example e1(12);
    e1.display();

    return 0;
}