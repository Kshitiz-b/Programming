#include <iostream>
using namespace std;

template <class T1 = int, class T2 = float, class T3 = string>
class Kshitiz
{
public:
    T1 a;
    T2 b;
    T3 s;

    Kshitiz(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        s = z;
    }

    void display()
    {
        cout << "The value of a is: " << a << endl;
        cout << "The value of b is: " << b << endl;
        cout << "The string is: " << s << endl << endl;
    }
};

int main()
{
    Kshitiz<> k1(4, 5.8, "WOW");
    k1.display();
    
    Kshitiz<float, char, char> k2(1.4, 'o', 'c');
    k2.display();

    return 0;
}