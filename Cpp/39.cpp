#include <iostream>
using namespace std;

int add(int a, int b)
{
    cout << "using function with 2 args" << endl;
    return a+b;

}

int add(int a, int b, int c)
{
    cout << "using function with 3 args" << endl;
    return a+b+c;
}

int main()
{
    cout << "\nthe sum of 3, 6 is " << add(3, 6);
    cout << "\nthe sum of 3, 7, 6 is " << add(3, 7, 6);
    
    return 0;
}