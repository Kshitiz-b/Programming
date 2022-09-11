// Implementation of queue using Array
#include <stdio.h>
int front = -1;
int rear = -1;

void Enqueue(int A[], int n, int X)
{
    if (rear == n - 1)
        printf("Queue is Full\n");
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        A[rear] = X;
    }
    else
    {
        rear++;
        A[rear] = X;
    }
}

void Front(int A[])
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty\n");
    else
    {
        printf("\nThe Element at front is: %d\n", A[front]);
    }
}

void Dequeue(int A[])
{

    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("\n%d is Deleted\n", A[front]);
        front++;
        Display(A);
    }
}

void Display(int A[])
{
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("The Queue is:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", A[i]);
        }
    }
}

int main()
{
    int n, X;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &X);

        Enqueue(A, n, X);
    }
    Enqueue(A, n, 45);
    Display(A);
    Dequeue(A);
    Front(A);

    return 0;
}