#include <iostream>
using namespace std;

class media
{
protected:
    string author;

public:
    virtual void getdata() = 0;
    virtual void display() = 0;
};

class book : public media
{
    int pages;

public:
    void getdata()
    {
        author = "kshitiz";
        pages = 500;
    }
    void display()
    {
        cout << "The book details are: " << author << "\t" << pages;
    }
};

class tape : public media
{
    int duration;
    string author;
    int pages;

public:
    void getdata()
    {
        author = "rama";
        pages = 420;
    }
    void display()
    {
        cout << "\nThe tape details are: " << author << "\t" << pages;
    }
};

int main()
{
    // virtual functions
    // Real - time applications of virtual functions
    media *ptr;

    book b;
    ptr = &b;
    ptr->getdata();
    ptr->display();

    tape t;
    ptr = &t;
    ptr->getdata();
    ptr->display();

    return 0;
}