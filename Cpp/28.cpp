#include<iostream>
using namespace std;
class Account
{
    public:
    int no;
    string name;
    float balance;
    string toa;
    
    void getdata(int n, string na, float bal, string to)
    {
        no=n;
        name=na;
        balance=bal;
        toa=to;
        
    }
    
    void deposit(float x)
    {
        balance +=x;
        cout<<endl<<"deposit success";
        
    }
    void getbalance()
    {
        cout<<endl<<"The balance is: "<<balance;
    }
    
};

 

class SA : public Account
{
    public:
    void interest()
    {
        cout<<endl<<"Interest calculated";
    }
    void withdraw(float x)
    {
        balance -=x;
        cout<<endl<<"withdraw sucess";
    }
    
};
class CA : public Account
{
    public:
    float minbalance;
    void checkbook()
    {
        cout<<"checkbook facility";
    }
    void withdraw(float x)
    {
        balance -=x;
        if(balance<minbalance)
        {
            cout<<"minimum balance crossed";
        }
        cout<<"withdraw sucess";
    }
    
    
};

 

int main()
{

 

    SA s;
    s.getdata(1111, "naga", 1000, "saving");
    s.getbalance();
    s.deposit(1500);
    s.getbalance();
    s.withdraw(750);
    s.getbalance();
    
    CA c;
    
    return 0;
}