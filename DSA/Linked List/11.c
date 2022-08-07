// Deleting an element on a given index in a linked list
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
    if (p != NULL)
    {
        printf("List->");
    }
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    if (p == NULL)
    {
        printf("NULL");
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q=NULL;
    int x = -1, i;

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int A[n], index;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &index);

    create(A, n);

    display(first);
    printf("\n");

    if (index < 1 || index > n)
    {
        printf("NO");
    }
    else
        Delete(first, index);
        display(first);
    return 0;
}