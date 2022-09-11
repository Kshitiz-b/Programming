#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
const int max = 20;
int stack[20], top = 0, x1, x2;

void fun_push(int n)
{
    if (top >= max)
        printf("\nStack is full\n");
    else
    {
        top++;
        stack[top] = n;
    }
    
}
void fun_pop()
{
    x2 = stack[top];
    top--;
    x1 = stack[top];
 
}

void fun_eval(char c, int x1, int x2)
{
    int x;
    switch (c)
    {
    case '+':
        x = x1 + x2;
        break;
    case '-':
        x = x1 - x2;
        break;
    case '*':
        x = x1 * x2;
        break;
    case '/':
        x = x1 / x2;
        break;
    case '^':
        x = pow(x1, x2);

    }
    stack[top] = x;
}

int main()
{
    char c, ch[2], arr[25];
    int i, len, t;
    scanf("%s", arr);
    len = strlen(arr);
    for (i = 0; i < len; i++)
    {
        if (isdigit(arr[i]))
        {
            ch[0] = arr[i];
            ch[1] = '\0';
            t = atoi(ch);
            fun_push(t);
        }
        else
        {
            c = arr[i];
            fun_pop();
            fun_eval(c, x1, x2);
        }
    }
    printf("%d", stack[1]);
    getch();

    return 0;
}