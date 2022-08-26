#include <stdio.h>
#define N 50
void insert();
void delete ();
void display();
int queue[N] = {1,2,3,4,5};
int front = -1;
int rear = -1;

int main()
{
    int choice;
    while (choice)
    {
        printf("1. To insert element: \n");
        printf("2. To delete element: \n");
        printf("3. To display element: \n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert ();
        }
        else if (choice == 2)
        {
            delete ();
        }
        else if (choice == 3)
        {
            display ();
        }
        else
        {
            printf("Wrong input\n");
        }
    }
}
void insert()
{
    int x;
    if (queue == (N - 1))
    {
        printf("Overflow condition\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void delete ()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow Condition\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Underflow Condition\n");
    }
    else
    {
        
        for (i = front; i <= rear; i++)
        {
            printf("%d", queue[i]);
        }
    }
}