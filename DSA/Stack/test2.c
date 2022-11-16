#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define n 20
int stack[n];
int top = -1;
void Push(char);
char Pop();

int main()
{
    char exp[n], temp;
    int i, flag = 1;
    scanf("%s", exp);

    for (i = 0; i < strlen(exp); i++)
    {
        if ((exp[i] == '(') || (exp[i] == '{') || (exp[i] == '['))
            Push(exp[i]);
        if ((exp[i] == ')') || (exp[i] == '}') || (exp[i] == ']'))

        {
            if (top == -1)
            {
                flag = 0;
            }

            else
            {
                temp = Pop();
                if ((exp[i] == ')') && ((temp == '{') || (temp == '[')))
                    flag = 0;
                if ((exp[i] == '}') && ((temp == '(') || (temp == '[')))
                    flag = 0;
                if ((exp[i] == ']') && ((temp == '{') || (temp == '(')))
                    flag = 0;
            }
        }
    }
    if (top >= 0)
    {
        flag = 0;
    }
    if (flag == 0)
    {
        printf("Not Balanced");
    }
    else
    {
        printf("Balanced");
    }

    return 0;
}
void Push(char c)
{
    if (top == (n - 1))
        printf("Stack Overflow\n");
    else
    {
        top = top + 1;
        stack[top] = c;
    }
}
char Pop()
{

    if (top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}