// Add After
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

void AddLast(int T, int X)
{
    struct Node *l;
    struct Node *temp;

    if (list == NULL)
    {
        printf("List is Empty\n");
    }

    else
    {
        while (l->data != T && l->next != NULL)
            l = l->next;

        if (l->data == T)
        {
            temp = malloc(sizeof(struct Node));
            temp->data = X;
            temp->next = l->next;
            l->next = temp;
        }
        else
            printf("Target Element Not Found\n");
    }
}

int main()
{
    int n, i, T, X;
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
    AddLast(T, X);
    Display();

    return 0;
}