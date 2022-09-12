// using Arrays
#include <stdio.h>

#define N 5
int deque[N];
int F = -1, R = -1;

void enQueue(int x) // insertion at rear
{
    if ((F == 0 && R == N - 1) || (F == R + 1))
        printf("Deque is Full\n");
    else if (F == -1)
    {
        F = R = 0;
        deque[R] = x;
    }
    else if (R == N - 1)
    {
        R = 0;
        deque[R] = x;
    }
    else
    {
        R = R + 1;
        deque[R] = x;
    }
}

void deQueue() // deletion at front
{
    if (F == -1 && R == -1)
        printf("Deque is Empty\n");
    else if (F == R)
    {
        printf("%d is deleted\n", deque[F]);
        F = R = -1;
    }
    else if (F == N - 1)
    {
        printf("%d is deleted\n", deque[F]);
        F = 0;
    }
    else
    {
        printf("%d is deleted\n", deque[F]);
        F = F + 1;
    }
}

void Push(int x) // insertion at front
{
    if ((F == 0 && R == N - 1) || (F == R + 1))
        printf("Deque is Full\n");
    else if (F == -1)
    {
        F = R = 0;
        deque[F] = x;
    }
    else if (F == 0)
    {
        F = N - 1;
        deque[F] = x;
    }
    else
    {
        F = F - 1;
        deque[F] = x;
    }
}

void Pop() // deletion at rear
{
    if (F == -1 && R == -1)
        printf("Deque is Empty\n");
    else if (F == R)
    {
        printf("%d is deleted\n", deque[R]);
        F = R = -1;
    }
    else if (R == 0)
    {
        printf("%d is deleted\n", deque[R]);
        R = N - 1;
    }
    else
    {
        printf("%d is deleted\n", deque[R]);
        R = R - 1;
    }
}

void Display()
{
    int i=F;
    if (F == -1)
        printf("Deque is Empty\n");
    else
    {
        printf("Front ");
        while (i != R)
        {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d Rear\n", deque[R]);
    }
}

int main()
{
    int x, choice;

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &x);
            enQueue(x);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            scanf("%d", &x);
            Push(x);
            break;
        case 4:
            Pop();
            break;
        case 5:
            Display();
            break;
        }

    } while (choice != 6);

    return 0;
}