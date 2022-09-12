#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int X)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = X;

    if (front == NULL)
        front = temp;
    else
        rear->next = temp;

    rear = temp;
    rear->next = front;
}

void Dequeue()
{
    struct Node *l;

    if (front == NULL)
        printf("Queue is Empty\n");
    else if (front != rear)
    {
        printf("%d is deleted\n", front->data);
        l = front;
        front = front->next;
        rear->next = front;
    }
    else
    {
        printf("%d is deleted\n", front->data);
        l = front;
        front = rear = NULL;
    }
    free(l);
}

void Display()
{
    struct Node *l;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        printf("Circular Queue:");
        for (l = front; l->next != front; l = l->next)
            printf("%d ", l->data);
        printf("%d\n", l->data);
    }
}

int main()
{
    int choice, X;

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &X);
            Enqueue(X);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        }
    } while (choice != 4);

    return 0;
}