#include <iostream>
using namespace std;

// pointers

int main()
{
    // basic example
    int a = 4;
    int *ptr = &a;

    cout << "The value of a is " << *(ptr) << endl;

    // new keyword
    int *p = new int(40);
    cout << "The value at adderss p is " << *(p) << endl;

    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20; 
    arr[2] = 30; 
    cout << "the value of arr[0] is " << arr[0] << endl;
    cout << "the value of arr[1] is " << arr[1] << endl;
    cout << "the value of arr[2] is " << arr[2] << endl;
    

    return 0;
}