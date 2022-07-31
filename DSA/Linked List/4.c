// Counting the nodes of a linked list
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

int count(struct Node *p)
{
    int l = 0;

    while (p!=NULL)
    {
        l++;
        p=p->next;
    }

    return l;
}

int Rcount(struct Node *p)  // using recursion
{
    if(p!=NULL)
        return Rcount(p->next)+1;

    else 
        return 0;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    display(first);

    printf("\nLength is %d\n", count(first));
    printf("Length using recursion is %d\n", Rcount(first));

    return 0;
}