// Maximum element in a linked list

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

int Max(struct Node *p)
{
    int m = INT_MIN;
    int temp;

    while (p != NULL)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }

    return m;
}

int RMax(struct Node *p)    // Using Recursion
{
    int x = 0;

    if (p == NULL)
    {
        return INT_MIN;
    }
    else
    {
        x = RMax(p->next);
        if (x > p->data)
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
    printf("\nThe max element is %d", Max(first));
    printf("\nThe max element using Recursion is %d", RMax(first));


    return 0;
}