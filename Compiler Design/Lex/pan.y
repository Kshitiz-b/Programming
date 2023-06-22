%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern char* yytext;

int yyparse();
void yyerror(const char* msg);

#define PAN_NUMBER 1

%}

%token PAN_NUMBER

%%
input:
    PAN_NUMBER { printf("Valid PAN Card Number: %s\n", $1); free($1); }
    | error { yyerror("Invalid PAN Card Number"); }
    ;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int main() {
    yyparse();
    return 0;
}
