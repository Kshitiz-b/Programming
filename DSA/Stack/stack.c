// using Array
#include <stdio.h>
int top = -1;

void Push(int A[], int n)
{
    int x;

    scanf("%d", &x);
    if (top == n - 1)
        printf("Stack is Full\n");
    else
    {
        top++;
        A[top] = x;
    }
}

void Pop(int A[])
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("\n%d is Deleted\n", A[top]);
        top--;
    }

}

void Display(int A[], int n)
{
    if (top == -1)
        printf("Stack is Empty\n");

    else
    {
        for (int i = 0; i <= top; i++)
            printf("%d ", A[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of stack: ");
    scanf("%d", &n);

    int A[n];

    int choice;
    printf("1. Push()\n2. Pop()\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the elements you want to insert\n");
        for (int i = 0; i < n; i++)
        {
            Push(A, n);
        }
        printf("After Insertion\n");
        Display(A, n);

    case 2:
        Pop(A);
        Display(A, n);
        break;
    }

    return 0;
}