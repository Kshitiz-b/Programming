// Inserting after a given element
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
    if (p == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List->");
        while (p != NULL)
        {
            printf("%d->", p->data);
            p = p->next;
        }
        printf("NULL");
    }
}

void Insert(struct Node *l, int T, int X)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;

    for (l = first; l->next != NULL && l->data != T; l = l->next);

    if (l->data != T)
    {
        printf("Target Element is Not Found\n");
        
    }
    else
    {
        temp->next = l->next;
        l->next = temp;
        display(first);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create(A, n);

    int T;
    scanf("%d", &T);

    int X;
    scanf("%d", &X);

    display(first);
    printf("\n");

    printf("After Insertion\n");
    Insert(first, T, X);

    return 0;
}