#include <stdio.h>
#include <string.h>

struct s
{
    int stack[100];
    int sp;
} st;

void init()
{
    st.sp = -1;
}

void push(int ele)
{
    st.stack[++st.sp] = ele;
}

int pop()
{
    return st.stack[st.sp--];
}

int doOperation(int op1, int op2, char ch)
{
    switch (ch)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 & op2;
    }
    return -1;
}

void evaluate(char s[])
{
    char ch;
    int op1;
    int op2;
    int ch_count = 0, op_count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        ch = s[i];

        if ((ch >= '0') && (ch <= '9'))
        {
            push(ch - 48);
            ch_count++;
        }
        else
        {
            op_count++;
            op2 = pop();
            op1 = pop();

            int result = doOperation(op1, op2, ch);
            push(result);
        }
    }

    if (ch_count == op_count)
        printf("Not Valid Postfix Expression");
    else
        printf("%d", st.stack[st.sp]);
}

int main()
{
    init();
    char s[100];
    // printf("\n Enter the postfix Expression: ");
    scanf("%s", s);
    evaluate(s);
    return 0;
}
