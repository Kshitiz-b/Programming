// Implementation of circular queue using Array
#include <stdio.h>
int front = -1;
int rear = -1;
int n=5;
int A[];

void Enqueue(int X)
{
    if (((rear + 1) % n) == front)
        printf("Queue is Full\n");
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        A[rear] = X;
    }
    else
    {
        rear = (rear + 1) % n;
        A[rear] = X;
    }
}

void Dequeue()
{

    if (front == -1)
        printf("Queue is Empty\n");
    else if (front == rear)
    {
        printf("%d is Deleted\n", A[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is Deleted\n", A[front]);
        front = (front + 1) % n;
    }
}

void Display()
{
    if (front == -1)
        printf("Queue is Empty\n");
    if (rear >= front)
    {
        printf("Circular Queue:");
        for (int i = front; i <= rear; i++)
            printf("%d ", A[i]);
    }
    else
    {
        printf("Circular Queue:");
        for (int i = front; i < n; i++)
            printf("%d ", A[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", A[i]);
    }

    printf("\n");
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