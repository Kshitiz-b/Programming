#include <iostream>
using namespace std;
class account
{
    string name;
    int number;
    string type;
    string status;
    float balance;

public:
    void input()
    {
        cout << "Enter the name number type status balance:\n";
        cin >> name >> number >> type >> status >> balance;
    }

    void display()
    {
        cout << "\n" << name;
        cout << "\n" << number;
    }

    void withdraw(float x)
    {

        if (balance > 1000)
        {
            balance = balance - x;
            cout << "\nbalance after withdrawl: " << balance;
        }
        else
        {
            cout << "\nInsufficient funds!";
        }
    }
};

int main()
{
    float with;
    account a1;
    a1.input();
    a1.display();

    cout << "Enter the amount to be withdrawn: ";
    cin >> with;

    a1.withdraw(with);

    return 0;
}