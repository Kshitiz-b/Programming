%{
#include <stdio.h>
int operatorCount = 0;
int identifierCount = 0;
int keywordCount = 0;
int specialSymbolCount = 0;
%}

%%
"if"|"else"|"while"|"for"|"int"|"float"|"char"|"printf"|"main"|"scanf"    {
                                                    keywordCount++;
                                                }
"=="|"!="|"<"|">"|"<="|">="|"+"|"-"|"*"|"/"|"%"    {
                                                        operatorCount++;
                                                    }
[a-zA-Z_][a-zA-Z0-9_]*   {
                            identifierCount++;
                          }
[^\t\n\r\f\v a-zA-Z0-9_(){};]    {
                                specialSymbolCount++;
                            }
.                       /* Ignore any other characters */
%%

int yywrap(){}

int main() {
    yyin = fopen("prog.c","r");
    yylex();
    printf("Operator count: %d\n", operatorCount);
    printf("Identifier count: %d\n", identifierCount);
    printf("Keyword count: %d\n", keywordCount);
    printf("Special symbol count: %d\n", specialSymbolCount);
    return 0;
}