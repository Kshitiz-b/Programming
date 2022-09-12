// using Linked list for Char input
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[10];
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(char X[])
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    strcpy(temp->data, X);
    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void Dequeue()
{
    struct Node *l;

    if (front == NULL)
        printf("Queue is Empty\n");
    else if (front != rear)
    {
        printf("%s is deleted\n", front->data);
        l = front;
        front = front->next;
    }
    else
    {
        printf("%s is deleted\n", front->data);
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
        printf("FRONT->");
        for (l = front; l->next != NULL; l = l->next)
            printf("%s->", l->data);
        printf("%s->REAR\n", l->data);
    }
}

int main()
{
    int choice;
    char X[10];

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%s", X);
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