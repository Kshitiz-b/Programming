#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int max = 20;
char stack[20];
int top = 0;
void fun_push(char c)
{
    if (top >= max)
        printf("\nStack is full\n");
    else
    {
        top++;
        stack[top] = c;
    }
}
void fun_pop()
{
    if (top > 0)
    {
        top--;
    }
    else if (top == 0)
    {
        top--;
    }
}
void fun_abal()
{
    if (top == 0)
        printf("Balanced\n");
    else if (top < 0)
        printf("Not Balanced\n");
    else
        printf("Not Balanced\n");
}
int main()
{
    char arr[20];
    int i, len;
    scanf("%s", arr);
    len = strlen(arr);
    int flag = 1;
    for (i = 0; i < len; i++)
    {
        if ((arr[i] == '(' && arr[i + 1] == ')') || (arr[0] == ')'))
        {
            printf("Not Balanced");
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        for (i = 0; i < len; i++)
        {
            if (arr[i] == '(')
                fun_push(arr[i]);
            else if (arr[i] == ')')
                fun_pop();
        }
        fun_abal();
    }
    return 0;
}