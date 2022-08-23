// Finding middle element of a Circular DLL
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

    if (list == NULL)
        printf("List is Empty\n");
    else
    {
        printf("List<=>");
        for (l = list; l->next != list; l = l->next)
            printf("%d<=>", l->data);
        printf("%d<=>List\n", l->data);
    }
}

void Middle(int n)
{
    struct Node *l;
    struct Node *p;

    p = list;
    for (l = list; l->next != list; l = l->next)
        ;
    // do
    // {
    //     p = p->next;
    //     l = l->prev;

    // } while (l != p);

    // for (;l!=p;l=l->prev,p=p->next);

    if (n % 2 != 0)
    {
        while (l != p)
        {
            p = p->next;
            l = l->prev;
        }
    }
    else{
        while (l != p)
        {
            l = l->prev;
            if (l!=p)
            {
                p = p->next;
            }
        }
    }

    if (l == p)
    {
        printf("Middle Element: %d", l->data);
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
    Middle(n);

    return 0;
}