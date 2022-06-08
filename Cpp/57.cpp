#include <iostream>
using namespace std;

template <class T1, class T2>

float funcAvg(T1 a, T2 b)
{
    float avg = (a+b)/2.0;
    return avg;
}

int main()
{
    float a;
    a = funcAvg(5, 2);
    cout << "\nThe avg of the numbers is " << a;
    
    return 0;
}