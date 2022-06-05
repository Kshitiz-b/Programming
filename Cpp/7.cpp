#include<iostream>
using namespace std;

class book
{
    private:
    string author;
    int pages;
    float price;

    public:
    void readdata()
    {
        cout << "\nEnter author, pages, price";
        cin >> author >> pages >> price;
    }

    void displaydata()
    {
        cout << "\n The Book Details are: ";
        cout << author << "\t" << pages << "\t" << price;
    }

};


int main()
{
    book java;

    java.readdata();
    java.displaydata();

    book cpp;

    cpp.readdata();
    cpp.displaydata();

    return 0;
}
