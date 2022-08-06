// inserting in a linked list
// Display a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert(struct Node *p, int T, int X)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = X;

    if(T==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<T-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    display(first);
    Insert(first, 0, 10);
    display(first);

    return 0;
}