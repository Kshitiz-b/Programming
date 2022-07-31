// Addition of all the elements in a linked list using recursion
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
}

int RAdd(struct Node *p)
{

    if (p == 0)
        return 0;
    else
        return RAdd(p->next) + p->data;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    display(first);

    printf("\nThe sum using Recursion is: %d\n", RAdd(first));

    return 0;
}