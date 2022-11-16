// Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *list = NULL;

void Push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = x;
    if (t == NULL)
        printf("Stack is Full\n");
    else if (top != NULL)
    {
        top->next = t;
        top = t;
    }
    else
    {
        list = t;
        top = t;
    }
}

void Pop()
{
    struct Node *l;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        for (l = list; l->next != top && l->next != NULL; l = l->next)
            ;

        printf("%d is popped from stack\n", top->data);
        if (top != list)
        {
            l->next = NULL;
            free(top);
            top = l;
        }
        else
        {
            list = top = NULL;
            free(l);
        }
    }
}

void Display()
{
    struct Node *l;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        for (l = list; l->next != NULL; l = l->next)
            printf("%d->", l->data);
        printf("%d->top\n", l->data);
    }
}

int main()
{
    int choice, x;

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &x);
            Push(x);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        }
    } while (choice != 4);

    return 0;
}