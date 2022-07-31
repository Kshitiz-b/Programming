#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    

}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first=(struct Node *)malloc(siezeof(struct Node));
    first->data=A[0]
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    
    return 0;
}