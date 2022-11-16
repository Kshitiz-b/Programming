#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define n 50
int A[n];
int top = -1;
char temp[100];

void Push(char A[], char X)
{
    if (top == n - 1)
        printf("Stack is Full\n");
    else
    {
        top++;
        A[top] = X;
    }
}

char Pop(char A[])
{
    char X = ' ';
    if (top == -1)
        printf("Stack is Empty\n");
    else
    {
        X = A[top];
        top--;
    }
    return X;
}

int getPrio(char op)
{
    if ((op == '*') || (op == '/') || (op == '%'))
        return 1;
    else if ((op == '+') || (op == '-'))
        return 0;
}

void in_post(char source[], char target[])
{
    int i = 0, j = 0;

    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            Push(A, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (A[top] != '('))
            {
                target[j] = Pop(A);
                j++;
            }
            if (top == -1)
            {
                printf("\nNot Valid Infix Expression\n");
                exit(1);
            }
            temp = Pop(A); // remove left parentheses
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (A[top] != '(') && (getPrio(A[top]) >= getPrio(source[i])))
            {
                target[j] = Pop(A);
                j++;
            }
            Push(A, source[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while ((top != -1) && (A[top] != '('))
    {
        target[j] = Pop(A);
        j++;
    }
    target[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    // printf("Enter the infix expression:\n");
    scanf("%s", &infix);
    strcpy(postfix, "");
    in_post(infix, postfix);
    printf("\n%s\n", postfix);

    return 0;
}