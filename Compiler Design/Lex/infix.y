%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char* msg);

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infix_to_postfix(const char* infix, char* postfix) {
    int i, j;
    char c;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(1);
            }
            pop(); // Discard the '('
        } else if (is_operator(c)) {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc '(' ')'

%%

input: expr
      {
        char postfix[MAX_SIZE];
        infix_to_postfix($1, postfix);
        printf("Postfix expression: %s\n", postfix);
      }
      ;

expr: expr '+' expr   { $$ = $1; printf("+ "); }
    | expr '-' expr   { $$ = $1; printf("- "); }
    | expr '*' expr   { $$ = $1; printf("* "); }
    | expr '/' expr   { $$ = $1; printf("/ "); }
    | expr '^' expr   { $$ = $1; printf("^ "); }
    | '(' expr ')'    { $$ = $2; }
    | NUMBER          { $$ = $1; printf("%d ", $1); }
    ;

%%

void yyerror(const char* msg) {
    printf("Error: %s\n", msg);
}

int main() {
    yyparse();
    return 0;
}
