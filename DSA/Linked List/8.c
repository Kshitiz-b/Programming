// Minimum element in a linked list

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

int Min(struct Node *p)
{
    int m = INT_MAX;

    while (p != NULL)
    {
        if (p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }

    return m;
}

int RMin(struct Node *p) // Using Recursion
{
    int x = 0;

    if (p == NULL)
    {
        return INT_MAX;
    }
    else
    {
        x = RMin(p->next);
        if (x < p->data)
        {
            return x;
        }
        else
            return p->data;
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    display(first);
    printf("\nThe min element is %d", Min(first));
    printf("\nThe min element using Recursion is %d", RMin(first));

    return 0;
}