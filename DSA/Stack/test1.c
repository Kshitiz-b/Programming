#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define n 10
float A[n];
int top = -1;
void Push(float A[], float X)
{
    if (top == n - 1)
        printf("\nStack is Full");
    else
    {
        top++;
        A[top] = X;
    }
}
float Pop(float A[])
{
    float X = -1;
    if (top == -1)
        printf("\nStack is Empty");
    else
    {
        X = A[top];
        top--;
    }
    return X;
}
float evaluatePost(char exp[100])
{
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
            Push(A, (float)(exp[i] - '0'));
        else if (top == 0)
        {
            printf("Not Valid Postfix Expression");
            exit(0);
        }
        else
        {
            op2 = Pop(A);
            op1 = Pop(A);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            case '^':
                value = pow((int)op1, (int)op2);
            }
            Push(A, value);
        }
        i++;
    }
    return (Pop(A));
}

int main()
{
    float X;
    char exp[100];
    scanf("%s", exp);
    X = evaluatePost(exp);
    printf("%.0f", X);
    return 0;
}