// Add Begin
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
    int i;
    struct Node *t, *last;

    list = (struct Node *)malloc(sizeof(struct Node));
    list->data = A[0];
    list->next = list;
    last = list;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display()
{
    struct Node *l;

    if (list == NULL)
        printf("List is Empty\n");
    else
    {
        printf("List->");
        for (l = list; l->next != list; l = l->next)
            printf("%d->", l->data);
        printf("%d->List\n", l->data);
    }
}

void AddBegin(int T)
{
    struct Node *l;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = T;
    temp->next = list;

    for (l = list; l->next != list; l = l->next);
    l->next = temp;
    list = temp;
}

int main()
{
    int n, i, T;
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &T);

    create(A, n);
    Display();
    AddBegin(T);
    Display();

    return 0;
}