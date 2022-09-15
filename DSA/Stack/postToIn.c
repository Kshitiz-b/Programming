#include <stdio.h>
//#include <conio.h>
#include <string.h>
#define MAX 20
char str[MAX], stack[MAX];
int top = -1;
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
void post_in()
{
    int i, n;
    char a, b, op;
    printf("Enter the postfix expression\n");
    char str[10];
    scanf("%s", str);
    n = strlen(str);
    for (i = 0; i < MAX; i++)
        stack[i] = NULL;
    // printf("Infix expression is:\t");
    printf("(%c", str[0]);
    for (i = 1; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            b = pop();
            // a=pop();
            op = str[i];
            printf("%c%c)", op, b);
        }
        else
        {
            push(str[i]);
        }
    }
    // printf("%c",str[top--]);
}
void main()
{
    post_in();
}
