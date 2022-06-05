#include<iostream>
using namespace std;

class vector
{
    private:
    float i;
    float j;
    float k;
    int scalar;
    

    public:
    void readdata()
    {
        cout << "Enter the i, j, k: \n";
        cin >> i >> j >> k;
    }

    void displaydata()
    {
        cout << "The entered vector is: \n";
        cout << i << ", " << j << ", " << k;
    }
    
    void multiply()
    {
        cout << "Enter the scalar value: ";
        cin >> scalar;

        cout << i*scalar << ", " << j*scalar << ", " << k*scalar;  
    }
    
};

int main()
{
    vector v1;
    v1.readdata();
    v1.displaydata();
    v1.multiply();
    

    return 0;
}