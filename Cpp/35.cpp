#include <iostream>
using namespace std;

class person
{
public:
    string name;
    int code;

    void read1(string na, int co)
    {
        name = na;
        code = co;
    }
};
class pay : virtual public person
{
public:
    float pay;

    void read2(float pa)
    {
        pay = pa;
    }
};

class admin : virtual public person
{
public:
    int experience;

    void read3(int exp)
    {
        experience = exp;
    }
};

class master : public pay, public admin
{
public:

    void display()
    {
        cout << name << endl << code << endl << pay << endl << experience; 
    }
};


int main()
{
    master m1;
    m1.read1("Kshitiz", 2067);
    m1.read2(15346.213);
    m1.read3(5);
    m1.display();

    return 0;
}