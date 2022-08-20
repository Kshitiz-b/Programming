// Deleting a target element in DLL
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

void Delete(int T)
{
    struct Node *l;
    if (list != NULL)
    {
        for (l = list; l->next != NULL && l->data != T; l = l->next)
            ;
        if (l->data == T)
        {
            if (l->next == NULL && l->prev != NULL)
            {
                l->prev->next = NULL;
            }
            else
            {
                if (l == list)
                    list = list->next;

                else
                {
                    l->prev->next = l->next;
                    l->next->prev = l->prev;
                }
            }

            free(l);
        }
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
    Delete(T);
    Display();

    return 0;
}