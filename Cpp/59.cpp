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


int main()
{
    //Kshitiz<float> k(5.99);
    Kshitiz<int> k(87);

    cout << k.data << endl;
    k.display();

    return 0;
}