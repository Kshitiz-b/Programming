#include <stdio.h>

int front = -1, rear = -1;

void Enqueue(int A[], int n, int X)
{
    if ((rear == -1) && (front == -1))
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

void Dequeue(int A[], int n)
{
    if ((rear == -1) || (front > rear))
        printf("Queue is Empty\n");
    else
    {
        printf("%d is deleted\n", A[front]);
        front++;
    }
}

void Display(int A[], int n)
{
    if ((rear == -1) || (front > rear))
        printf("Queue is Empty\n");
    else
    {
        printf("FRONT->");
        for (int i = front; i <= rear; i++)
        {
            if(i==rear)
                printf("%d", A[i]);
            else
                printf("%d ", A[i]);
        }
        printf("->REAR\n");
    }
}

int main()
{
    int n=10;
    int A[n];

    Enqueue(A, n, 15);
    Enqueue(A, n, 25);
    Enqueue(A, n, 35);
    Enqueue(A, n, 45);
    Display(A, n);
    Dequeue(A, n);
    Dequeue(A, n);
    Display(A, n);
}