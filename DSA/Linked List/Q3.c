// insertion after a given target position
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

void Insert(struct Node *p, int T, int X)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = X;

    if (T == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < T - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
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

    if (T > n)
        printf("Position is Not Found\n");
    else
    {
        Insert(first, T, X);
        printf("After Insertion\n");
        display(first);
    }

    return 0;
}
