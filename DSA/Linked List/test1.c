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
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(int A[], int n)
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

void DeleteAfter(int A[], int n, int T)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == T)
        {
            flag = 1;
            break;
        }
        else
            flag = 0;
    }
    if (flag == 1)
    {
        struct Node *l = head, *p = head;
        while (l->data != T)
        {
            l = l->next;
        }
        l = l->next;
        if (l == head)
        {
            struct Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        }
        else
        {
            while (p->next != l)
            {
                p = p->next;
            }
            p->next = l->next;
            l = p;
        }

        display(A, n);
    }
    else
        printf("Target Element is Not Found\n");
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
    display(A, n);
    DeleteAfter(A, n, T);

    return 0;
}