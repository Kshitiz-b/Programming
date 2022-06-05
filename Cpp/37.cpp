// c++ program to find square and cube of a number using inheritance
#include <iostream>
using namespace std;

class number 
{
public:
    int num;

    void read()
    {
        cout << "\nEnter an integer: ";
        cin >> num;
    }
    void display1()
    {
        cout << "\nThe integer you entered is: " << num;
    }    
};

class square : virtual public number
{
public:
    int sq;

    void square1()
    {
        sq = num*num;
    }
};

class cube : virtual public number
{
public:
    int cu;

    void cube1()
    {
        cu = num*num*num;
    }
};

class master : public square, public cube
{
public:
    void display()
    {
        cout << "\nThe square of the given integer is: " << sq;
        cout << "\nThe cube of the given integer is: " << cu;
    }
};

int main()
{
    master m1;

    m1.read();
    m1.display1();
    m1.square1();
    m1.cube1();
    m1.display();

    return 0;
}