// DONT KNOW WHAT THE FUCK IS WRONG WITH IT
#include <iostream>
using namespace std;
int main() {
	int arr[5];

	for (int i=0;i<arr[5];i++)
	{
		cin >> arr[i];

	}

	for (int i=0;i<arr[5];i++)
	{
		if (arr[i]!=42)
		{
			cout << arr[i] << endl;
		}
		else
		{
			break;
		}
	}
}