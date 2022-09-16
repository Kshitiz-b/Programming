#include <stdio.h>
#include <string.h>
#include <ctype.h>

char operand_stack[50][80], operator_stack[50];
int top_operator = -1, top_operand = -1;
int push_operator(char operator)
{
    operator_stack[++top_operator] = operator;
}

int push_operand(char *opnd)
{
    strcpy(operand_stack[++top_operand], opnd);
}

char pop_operator()
{
    return (operator_stack[top_operator--]);
}

char *pop_operand()
{
    return (operand_stack[top_operand--]);
}

int empty(int t)
{
    if (t == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char prefix_expression[50], ch, temporary_string[50], operand_a[50], operand_b[50], operator[2];
    int count = 0, k = 0, operand_count = 0;
    //printf("\nEnter a Prefix Expression:\t");
    scanf("%s", prefix_expression);
    while ((ch = prefix_expression[count++]) != '\0')
    {
        if (isalnum(ch))
        {
            temporary_string[0] = ch;
            temporary_string[1] = '\0';
            push_operand(temporary_string);
            operand_count++;
            if (operand_count >= 2)
            {
                strcpy(operand_b, pop_operand());
                strcpy(operand_a, pop_operand());
                strcpy(temporary_string, "(");
                strcat(temporary_string, operand_a);
                ch = pop_operator();
                operator[0] = ch;
                operator[1] = '\0';
                strcat(temporary_string, operator);
                strcat(temporary_string, operand_b);
                strcat(temporary_string, ")");
                push_operand(temporary_string);
                operand_count = operand_count - 1;
            }
        }
        else
        {
            push_operator(ch);
            if (operand_count == 1)
            {
                operand_count = 0;
            }
        }
    }
    if (!empty(top_operand))
    {
        strcpy(operand_b, pop_operand());
        strcpy(operand_a, pop_operand());
        strcpy(temporary_string, "(");
        strcat(temporary_string, operand_a);
        ch = pop_operator();
        operator[0] = ch;
        operator[1] = '\0';
        strcat(temporary_string, operator);
        strcat(temporary_string, operand_b);
        strcat(temporary_string, ")");
        push_operand(temporary_string);
    }

    printf("%s", operand_stack[top_operand]);

    return 0;
}