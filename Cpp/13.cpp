#include<iostream>
using namespace std;

class account
{
    private:
    char name[20];
    int number;
    char type[20];
    float  balance;
    int choice;
    float deposit;
    float withdrawl;

    public:
    void readdata()
    {
        cout << "Enter name, account number, account type and balance:\n";
        cin >> name >> number >> type >> balance;
    }

    
    
    void dep()
    {
        cout << "Enter the amount to deposit:\n";
        cin >> deposit;

        balance += deposit;
        cout << "The updated balance is: " << balance;
    }
    

    void with()
    {
        cout << "\nThe current balance is: " <<balance;
        cout << "\nEnter the amount to withdraw: ";
        cin >> withdrawl;

        balance = balance - withdrawl;
        cout << "\nThe updated balance is: " << balance;
    }

    void details()
    {
        cout << "\nThe name of the account holder is: " << name;
        cout << "\nThe current balance is: " << balance;
    }
};

int main()
{
    account a1;

    a1.readdata();
    a1.dep();
    a1.with();
    a1.details();
    

    return 0;
}