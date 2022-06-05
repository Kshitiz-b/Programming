#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    string name;
    int age;
    string gender;

    void input1()
    {
        cout << "Enter the name age gender: ";
        cin >> name >> age >> gender;
    }
};

class Student
{
public:
    string regno;
    string programme;
    string school;
    float cgpa;

    void input2()
    {
        cout << "Enter regno programme school cgpa: ";
        cin >> regno >> programme >> school >> cgpa;
    }
};

class Sport : public Student, public Person
{
public:
    string level;
    string level1;
    string level2;
    

    void input3()
    {
        cout << "Enter the level of the player(state/national): ";
        cin >> level;
    }

    void cgpa_inc()
    {
        level1 = "state";
        level2 = "national"; 
        if (level == level1)
        {
            cgpa += 0.5;
        }
        else if(level == level2)
        {
            cgpa += 1;
        }
    }

    void display()
    {
        cout << "\nThe name of the student is: " << name;
        cout << "\nThe reistration number of the student is: " << regno;
        cout << "\nThe CGPA is: " << cgpa;
        cout << "\nThe level is: " << level;
    }
};

int main()
{

    Sport s1;
    s1.input1();
    s1.input2();
    s1.input3();
    s1.cgpa_inc();
    s1.display();

    return 0;
}