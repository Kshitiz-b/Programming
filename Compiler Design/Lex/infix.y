%{
#include <stdio.h>
#include <stdlib.h>
extern FILE* yyin;
void yyerror(const char* s);
extern int yylex();
extern int yyparse();
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

expression: NUMBER   { printf("%d ", $1); }
          | expression '+' expression   { printf("+ "); }
          | expression '-' expression   { printf("- "); }
          | expression '*' expression   { printf("* "); }
          | expression '/' expression   { printf("/ "); }
          | '(' expression ')'         { }

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}
