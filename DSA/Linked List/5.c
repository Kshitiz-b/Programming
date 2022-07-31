// Addition of all the elements in a linked list
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

int Add(struct Node *p)
{
    int sum = 0;

    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    display(first);

    printf("\nThe sum of all the elements in the linked list is: %d\n", Add(first));

    return 0;
}