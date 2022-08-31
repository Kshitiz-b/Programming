// Implementation of queue using Array
#include <stdio.h>
int front = -1;
int rear = -1;

void Enqueue(int A[], int n, int X)
{
    if (rear == n)
        printf("Queue is Full");
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

void Dequeue(int A[])
{

    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("\n%d is Deleted\n", A[rear]);
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
    Display(A);
    Dequeue(A);

    return 0;
}