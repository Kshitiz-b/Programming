// linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *list = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;

    list = (struct Node *)malloc(sizeof(struct Node));
    list->data = A[0];
    list->next = NULL;
    last = list;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void addLast(int X)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;
    struct Node *p;

    for (p = list; p->next != NULL; p = p->next)
        ;
    p->next = temp;
    temp->next = NULL;
    p = temp;
}

void addBegin(int X)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;

    temp->next = list;
    list = temp;
}

void addAfter(int X, int T)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;
    struct Node *p;

    for (p = list; p->next != NULL && p->data != T; p = p->next)
        ;
    if (p->data != T)
    {
        printf("Target Element is Not Found\n");
    }
    else
    {
        temp->next = p->next;
        p->next = temp;
    }
}

void addBefore(int X, int T)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;
    struct Node *p;
    struct Node *l;
    l = list;
    for (p = list; p->next != NULL && p->data != T; p = p->next)
        ;
    if (p != list)
        for (l = list; l->next != p; l = l->next)
            ;

    if (p->data != T)
    {
        printf("Target Element is Not Found\n");
    }
    else if (l != p)
    {
        temp->next = p;
        l->next = temp;
    }
    else if (l == p)
    {
        temp->next = list;
        list = temp;
    }
}

void InsertAfter(int X, int T)
{
    struct Node *p;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;
    p = list;

    if (T == 0)
    {
        temp->next = list;
        list = temp;
    }
    else
    {
        for (int i = 0; i < T - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void InsertBefore(int X, int T)
{
    struct Node *p;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = X;
    p = list;

    if (T == 0)
    {
        temp->next = list;
        list = temp;
    }
    else
    {
        for (int i = 0; i < T - 2; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void display()
{
    struct Node *p;
    p = list;

    if (p != NULL)
        printf("list->");
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    if (p == NULL)
        printf("NULL\n");
}

void reverse()
{
    struct Node *prevnode = NULL;
    struct Node *current = list, *nextnode = list;

    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        current->next = prevnode;
        prevnode = current;
        current = nextnode;
    }
    list = prevnode;
    printf("Reversed Linked List is:\n");
    display();
}

void RecursiveReverse(struct Node *p)
{
    if (p->next == NULL)
    {
        list = p;
        return;
    }
    RecursiveReverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    int n, X, T;
    scanf("%d", &n);
    int A[n];
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create(A, n);
    int choice;
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &X);
            addLast(X);
            break;
        case 2:
            scanf("%d", &X);
            addBegin(X);
            break;
        case 3:
            scanf("%d", &X);
            scanf("%d", &T);
            addAfter(X, T);
            break;
        case 4:
            scanf("%d", &X);
            scanf("%d", &T);
            addBefore(X, T);
            break;
        case 5:
            scanf("%d", &X);
            scanf("%d", &T);
            InsertAfter(X, T);
            break;
        case 6:
            scanf("%d", &X);
            scanf("%d", &T);
            InsertBefore(X, T);
            break;
        case 7:
            reverse();
            break;
        case 8:
            RecursiveReverse(list);
            break;
        case 9:
            display();
            break;
        }
    } while (choice != 0);

    return 0;
}