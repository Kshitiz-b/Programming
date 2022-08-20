// Add Before a target element
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
    list->prev = list->next = NULL;
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

    if (list == NULL)
        printf("List is Empty\n");
    else
    {
        printf("List->");
        for (l = list; l->next != NULL; l = l->next)
            printf("%d ", l->data);
        printf("%d->NULL\n", l->data);
    }
}

void AddBefore(int T, int X)
{
    struct Node *l;
    struct Node *temp;

    if (list == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        for (l = list; l->data != T && l->next != NULL; l = l->next)
            ;
        if (l->data == T)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = X;
            temp->prev = l->prev;
            temp->prev->next = temp;
            l->prev = temp;

            if (l == list)
                list = temp;

            Display();
        }
        else
            printf("Target Element Not Found\n");
    }
}

int main()
{
    int n, i, X, T;
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &T);
    scanf("%d", &X);

    create(A, n);
    Display();
    AddBefore(T, X);

    return 0;
}