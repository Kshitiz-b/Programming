#include <iostream>
using namespace std;

class sample
{
public:
    sample()
    {
        cout << "Without arguments";
    }
    sample(int a)
    {
        cout << endl << "One arguments";
    }
    sample(int a, int b)
    {
        cout << endl << "Two arguments";
    }

};

int main()
{
    sample s1;
    sample s2(34);
    sample s3(3, 4);
    
    return 0;
}