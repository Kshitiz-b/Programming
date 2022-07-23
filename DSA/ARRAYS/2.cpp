// increasing the size of an array in Cpp
#include <iostream>

int main()
{
    int *P = new int[5];
    int *Q = new int[10];

    for (int i = 0;i<5;i++)
    {
        Q[i] = P[i];
    }
    delete []P;
    P = Q;
    Q = NULL;

    
    
    return 0;
}