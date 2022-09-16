// not working
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[1000];
    struct Node *next;
};

struct Node *top = NULL;

void push(char value[])
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
}

char *pop()
{

    char *temp_data = top->data;
    top = top->next;
    return temp_data;
}

void prefix(char data)
{
    char str[1000] = "";
    char j[100];
    strcpy(j, pop());
    char ji[100];
    strcpy(ji, pop());

    char r[] = "(";

    char ri[] = ")";
    strcat(str, r);
    strcat(str, ji);
    strncat(str, &data, 1);
    strcat(str, j);

    strcat(str, ri);

    push(str);
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        if(exp[i] == '(')
            temp[j] = ')';
        else if(exp[i] == ')')
            temp[j] = '(';
        else
            temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}

int main()
{
    char arr[100];
    scanf("%s", arr);
    reverse(arr);
    char *ptr = arr;
    int i = 0;

    while (*ptr != '\0')
    {
        char str[2];
        str[0] = *ptr;
        str[1] = '\0';

        if (*ptr >= 'A' && *ptr <= 'Z')
        {
            push(str);
            i++;
        }
        else if (i < 2)
        {
            printf("Not Valid prefix Expression");
            exit(0);
        }
        else
        {
            prefix(*ptr);
        }
        ptr++;
    }

    char *ptr1 = pop();
    reverse(ptr1);

    printf("%s", ptr1);
}