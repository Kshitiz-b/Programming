// Delete next
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
        printf("List->");
        for (l = list; l->next != list; l = l->next)
            printf("%d ", l->data);
        printf("%d->List\n", l->data);
        }
}

void DeleteNext(int T)
{
    struct Node *l;
    struct Node *p;

    if (list != NULL)
    {
        for (l = list; l->next != list && l->data != T; l = l->next)
            ;
        if (l->data == T)
        {

            if (l->next != list)
            {
                p = l->next;

                if (p->next == list && p->prev != list)
                {
                    p->prev->next = list;
                    list->prev = p->prev;
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }

                Display();

                free(l);
                free(p);
            }
            else
                Display();
        }
        else
            printf("Target Element is Not Found\n");
    }
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

    return 0;
}