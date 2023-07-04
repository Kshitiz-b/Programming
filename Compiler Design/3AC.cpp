#include <iostream>

using namespace std;

int main()
{
    int X = 1;
    int Y = 2;
    int result;

    if (X > Y)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    cout << "t1 = " << X << endl;
    cout << "t2 = " << Y << endl;
    cout << "if t1 > t2 goto L1" << endl;
    cout << "t3 = 0" << endl;
    cout << "goto L2" << endl;
    cout << "L1: t3 = 1" << endl;
    cout << "L2: result = t3" << endl;

    return 0;
}
