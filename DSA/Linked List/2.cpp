#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *P;
    P = new Node;

    P->data=10;
    P->next=0;
};

int main()
{
    
    
    return 0;
}