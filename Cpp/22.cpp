#include <iostream>
using namespace std;

class example
{
    int a;

public:
   
    readdata()
    {
        cout << "\nEnter a value: ";
        cin >> a;
    }
    displaydata()
    {
        cout << "\nThe a value is: " << a;
    }
};

int main()
{
    // array of objects 
    // int a; int a[10]

    example e[3];

    int i;
    for(i=0;i<3;i++)
    {
        e[i].readdata();
    }

    for(i=0;i<3;i++)
    {
        e[i].displaydata();
    }

    return 0;
}