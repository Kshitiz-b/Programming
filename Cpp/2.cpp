#include<iostream>
using namespace std;

int main()
{
    // int, double, float, char
    // bool a; true or false
    
    int a, b, c;
    
    cout << "Enter integer a";
    cin >> a;   // console input    >> - extraction operator
    cout << "Enter integer b";
    cin >> b;
    //  cin >> a >> b; - read multiple values at a time
    c = a + b;

    cout << "The result is: " << c;

    return 0;
}

// in c++ library -cout is defined in multiple places