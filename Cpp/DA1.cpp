#include <iostream>
using namespace std;

class employee
{
public:
    string name1;
    int id;
    string pan1;
    float salary;

    void read1()
    {
        cout << "\nEnter the employee name, id, PAN, salary: \n";
        cin >> name1 >> id >> pan1 >> salary;
    }
};

class student
{
public:
    int id;
    long long int number;
    float credits;
    float cost;

    void read2()
    {
        cout << "\nEnter student id, number, credits, cost of credits: \n";
        cin >> id >> number >> credits >> cost;
    }
};

class tenant : public employee, public student
{
public:
    string name2;
    string pan2;
    float rent;

    void read3()
    {
        cout << "\nEnter the tenant name, PAN and monthly rent: \n";
        cin >> name2 >> pan2 >> rent;
    }

    void valid()
    {
        if (pan1 == pan2)
        {
            cout << "\nTHE TENANT IS A VALID EMPLOYEE\n";
        }

        else
        {
            cout << "\nTHE TENANT IS NOT AN EMPLOYEE\n";
        }
    }

    void money()
    {
        if ((salary - cost) >= rent)
        {
            cout << "THE TENANT HAS ENOUGH MONEY\n";
        }

        else
        {
            cout << "THE TENANT DOES NOT HAVE ENOUGH MONEY\n";
        }
    }
};

int main()
{
    tenant t1;
    t1.read1();
    t1.read2();
    t1.read3();
    t1.valid();
    t1.money();

    return 0;
}