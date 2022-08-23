// Displaying Circular DLL Fwd and Bwd
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *list = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    list = (struct Node *)malloc(sizeof(struct Node));
    list->data = A[0];
    list->prev = list->next = list;
    last = list;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display()
{
    struct Node *l;
    struct Node *p;

    if (list == NULL)
        printf("List is Empty\n");
    else
    {
        printf("Forward\n");
        printf("List->");
        for (l = list; l->next != list; l = l->next)
            printf("%d ", l->data);
        printf("%d->List\n", l->data);
        
        printf("Backward\n");
        printf("List->");
        for (l = list; l->next != list; l = l->next);
        for (; l->prev != l; l = l->prev)
            printf("%d ", l->data);
        printf("%d->List", l->data);
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
    Display();

    return 0;
}