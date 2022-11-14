#include <stdio.h>
#include <stdlib.h>
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
    printf("%d is deleted\n", A[front]);
    front++;
}

void display(int A[], int n)
{
    if (front == -1 || front > rear)
        printf("Queue is Empty");
    else
    {
        printf("FRONT->");
        for (int i = front; i <= rear; i++)
        {
            if (i == rear)
                printf("%d", A[i]);
            else
                printf("%d ", A[i]);
        }
        printf("->REAR\n");
    }
}

int main()
{
    int n = 100;
    int A[n];
    int X;

    int choice;

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &X);
            Enqueue(A, n, X);
            break;
        case 2:
            Dequeue(A, n);
            break;
        case 3:
            display(A, n);
            break;
        }
    } while (choice != 4);

    return 0;
}