// Deleting the next element in a Circular LL
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

void DeleteNext(int T)
{
    struct Node *l;
    struct Node *p;

    if (list != NULL)
    {
        for (p = l = list; l->next != list && l->data != T; p = l, l = l->next);
        if (l == p)
        {
            for (l = list;l->next != list;l = l->next);
            if (list == l)
                list = NULL;
            else
            {
                list = list->next;
                l->next = list;
            }
            free(p);
        }
        else
        {
            p->next = l->next;
            free(l);
        }
    }
    else
        printf("List is Empty\n");
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
    DeleteNext(T);
    Display();

    return 0;
}