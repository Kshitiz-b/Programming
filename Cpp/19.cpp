#include <iostream>
using namespace std;

inline void display()
{
    cout << "This is an example for inline function";
}


int main()
{
    display();  // extra workload to the operating system - context switching

    return 0;
}