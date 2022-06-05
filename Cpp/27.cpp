#include <iostream>
using namespace std;

class B // Base class or super class - public/private/protected
{
public:
    int a;
    void display1()
    {
        cout << "This is base class B\n";
    }
};

class D : public B // subclass or derived class 
{
public:
    void display2()
    {
        cout << "This is derived class D\n";
    }
};

int main()
{
    // Module 6 : Inheritance
    // Code reusablilty
    D obj;
    obj.display1(); // this is inherited feature 
    obj.display2(); // this is own feature


    return 0;
}