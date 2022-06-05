#include <iostream>
using namespace std;

class shapes
{
protected:
    float b;
    float h;
    
public:
    virtual void getdata() = 0;
    virtual void display_area() = 0;
};

class rectangle : public shapes
{
    float area;
public:
    void getdata()
    {
        b = 10;
        h = 20;
    }
    void display_area()
    {
        area = b*h;
        cout << "The area of the rectangle is: " << area;
    }
};

class triangle : public shapes
{
    float area;
public:
    void getdata()
    {
        b = 30;
        h = 40;
    }
    void display_area()
    {
        area = 0.5*b*h;
        cout << "\nThe area of the triangle is: " << area;
    }
};

int main()
{
    shapes *ptr;

    rectangle r;
    ptr = &r;
    ptr->getdata();
    ptr->display_area();

    triangle t;
    ptr = &t;
    ptr->getdata();
    ptr->display_area();


    return 0;
}