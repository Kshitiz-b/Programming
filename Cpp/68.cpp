#include <iostream>
using namespace std;

void func(int x)
{
    for (int i=0;i<x;i++)
    {
        printf("I understand Functions concept %d\n", i);
        
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    func(n);
    
    return 0;
}