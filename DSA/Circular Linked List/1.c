#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
};

struct Node *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

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

    if (head == NULL)
        printf("List is Empty\n");
    else
    {
        printf("List->");
        for (l = head; l->next != head; l = l->next)
            printf("%d->", l->data);
        printf("%d->List\n", l->data);
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

    return 0;
}