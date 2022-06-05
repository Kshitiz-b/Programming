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
        author = "Kshitiz";
        pages = 500;
        price = 1000;
    }

    void displaydata()
    {
        cout << "\n The Book Details are: ";
        cout << author << "\t" << pages << "\t" << price;
    }

};


int main()
{
    // c++ = c with classes

    // C - Procedure-Oriented Programming Language
    // Procedure - function/method/procedure/task ....
    // C++ - Object-Oriented
    // Object - contains data + functions as a single unit
    // collection of objects

    book java;  // book is called as class, java is called as variable/object/instance of a class

    java.readdata();
    java.displaydata();

    return 0;
}
// in structure, by default, the members are public.
// in class, by default, the members are private.