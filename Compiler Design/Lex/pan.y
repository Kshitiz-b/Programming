%{
#include <stdio.h>
int yylex();
void yyerror(const char* msg);
%}

%token PAN

%%
input: PAN
      {
        printf("Valid PAN number: %s\n", $1);
      }
      ;

%%

void yyerror(const char* msg) {
    printf("Error: %s\n", msg);
}

int main() {
    yyin = fopen("input.txt","r");
    yyparse();
    return 0;
}
