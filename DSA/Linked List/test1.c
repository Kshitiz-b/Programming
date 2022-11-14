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
    head->next = NULL;
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

void display()
{
    if (head == NULL)
        printf("List is Empty\n");
    else
    {
        printf("List->");
        struct Node *l = head;
        while (l->next != NULL)
        {
            printf("%d->", l->data);
            l = l->next;
        }
        printf("%d->NULL\n", l->data);
    }
}

void Deletion(int A[], int n, int T)
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

    if (flag == 0)
        printf("Target Element is Not Found\n");
    else
    {
        struct Node *l = head;
        while (l->data != T)
        {
            l = l->next;
        }
        if (l == head)
        {
            l = l->next;
            head = l;
        }
        else
        {
            struct Node *p = head;
            while (p->next != l)
            {
                p = p->next;
            }
            p->next = l->next;
            l = p;
        }
        
        printf("After Deletion\n");
        display();
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
    display(A, n);
    Deletion(A, n, T);

    return 0;
}