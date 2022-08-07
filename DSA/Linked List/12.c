// Searching in a linked list
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

struct Node * LSearch(struct Node *p, int T)
{
    while (p!=NULL)
    {
        if(T==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}


void Insert(struct Node *p, struct Node *index, int X)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = X;

    if (T == 1)
    {
        t->next = first;
        first = t;
        return;
    }
    else
    {
        for (int i = 0; i < T - 2 ; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int n, i, T, X;
    struct Node *temp;
    struct Node *index;
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &T);
    scanf("%d", &X);
    
    create(A, n);

    display(first);
    printf("\n");

    temp = LSearch(first, T);
    if(temp)
        index = temp;
        Insert(first, index, X);
        printf("\nKey is found: %d", temp->data);
    else
        printf("\nKey is not found\n");

    return 0;
}