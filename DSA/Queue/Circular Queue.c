// Implementation of circular queue using Array
#include <stdio.h>
int front = -1;
int rear = -1;

void Enqueue(int A[], int n, int X)
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

void Dequeue(int A[], int n)
{

    if (front == -1)
        printf("Queue is Empty\n");
    else if (front == rear)
    {
        printf("%d is Deleted\n", A[front]);
        front = rear = -1;
        Display(A, n);
    }
    else
    {
        printf("%d is Deleted\n", A[front]);
        front = (front + 1) % n;
        Display(A, n);
    }
}

void Display(int A[], int n)
{
    if (front == -1)
        printf("Queue is Empty\n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", A[i]);
    }
    else
    {
        for (int i = front; i < n; i++)
            printf("%d ", A[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", A[i]);
    }

    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    int A[n];

    Enqueue(A, n, 15);
    Enqueue(A, n, 45);
    Enqueue(A, n, 25);
    Enqueue(A, n, 10);
    Enqueue(A, n, 40);
    Display(A, n);
    Dequeue(A, n);
    Enqueue(A, n, 5);
    Display(A, n);
    Enqueue(A, n, 1);
    Dequeue(A, n);

    return 0;
}