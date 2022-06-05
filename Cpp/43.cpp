//Write C++ Program to display the cube of the number upto a given integer using friend function.
#include <iostream>
#include <math.h>
using namespace std;

class master
{
	public:
	int n;
	int i;
	
	void read()
	{
		cout << "\nEnter the number: ";
		cin >> n;
		
	}
	
	void cu()
	{
		
		for(i=1;i<n;i++)
		{
			cout << "The cube of " << i << " is " << (i*i*i) << endl;
		}
	}
	
	friend int show(master);
		
};

int show(master m)
{
	cout << "The cube of " << m.i << " is: " << (m.i*m.i*m.i);
}

int main()
{
    master m;
    m.read();
    m.cu();
    show(m);
    
    return 0;
}