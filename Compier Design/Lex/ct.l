%{
#include <stdio.h>
int wordCount = 0;
%}

%%
[cC][a-zA-Z]*[tT]    {
                        wordCount++;
                        printf("Word: %s\n", yytext);
                    }

\n                  {
                        
                        printf("Word count: %d\n", wordCount);
                    }
.                   
%%

int yywrap(){}

int main() {
    yyin = fopen("input.txt","r");

    yylex();
    return 0;
}
