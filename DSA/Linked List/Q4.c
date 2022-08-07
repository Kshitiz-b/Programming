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

void Insert(struct Node *p, int T, int X)
{
    struct Node *t;
    struct Node *index;
    int temp;

    t = (struct Node *)malloc(sizeof(struct Node));
    index = (struct Node *)malloc(sizeof(struct Node));
    t->data = X;

    while (p->next != NULL)
    {
        if (T == p->data)
        {
            index->next = p->next;
            temp = 1;
            break;
        }
        else
            temp = 0;
    }

    if (temp == 1)
    {
        if (index->next == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    else 
        printf("Target Element Not Found\n");
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

    Insert(first, T, X);
    printf("After Insertion\n");
    display(first);

    return 0;
}