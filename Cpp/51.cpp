#include <iostream>
using namespace std;

class account
{
public:
    string name;
    int number;
    string type;
    string status;
    float balance;
    int day;
    int month;
    int year;

    void input()
    {
        cout << "Enter the account holder name, account number, type, status, balance, day, month, year:\n";
        cin >> name >> number >> type >> status >> balance >> day >> month >> year;
    }

    void display()
    {
        cout << endl
             << name << endl
             << number << endl
             << type << endl
             << status << endl
             << balance << endl
             << day << "/" << month << "/" << year << endl;
    }

    void withdraw()
    {
        float x;
        cout << "\nEnter the amount you want to withdraw: ";
        cin >> x;
        if ((balance - x) > 1000)
        {
            balance = balance - x;
            cout << balance << endl;
        }
        else
        {
            cout << "INSUFFICIENT FUNDS!!\n";
        }
    }

    void change()
    {
        if (year < 2021)
        {
            status = "\ndormat\n";
            cout << status;
        }
        else
        {
            cout << status << endl;
        }
    }
};

int main()
{

    account a1;
    a1.input();
    a1.display();
    a1.withdraw();
    a1.change();

    return 0;
}