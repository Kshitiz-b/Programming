// Member functions and Overloading Template Functions
#include <iostream>
using namespace std;

template <class T>
class Kshitiz
{
public:
    T data;
    Kshitiz(T a)
    {
        data = a;
    }
    void display();
    

};

template <class T>
void Kshitiz<T>:: display()
{
    cout << data << endl;
}

void func(int a)
{
    cout << "First func() " << a << endl;
}

template<class T>
void func(T a)
{
    cout << "Template func() " << a << endl;
}

template<class T>
void func1(T a)
{
    cout << "Template func1() " << a << endl;
}

int main()
{
    
    func(4); // Exact match takes the highest priority
    func1(4);

    return 0;
}