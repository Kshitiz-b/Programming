#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

void convert(char exp[])
{
    int l, i, j = 0;
    char tmp[20];
    strrev(exp);
    l = strlen(exp);
    for (i = 0; i < 50; i++)
    {
        stack[i] = '\0';
    }
    
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
            push(exp[i]);
        else
        {
            tmp[j++] = exp[i];
            tmp[j++] = pop();
        }
    }
    tmp[j] = exp[top--];
    strrev(tmp);
    puts(tmp);
}

int main()
{
    char exp[50];

    
    gets(exp);
    convert(exp);
    return 0;
}