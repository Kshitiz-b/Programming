%{
#include <stdio.h>
#include <string.h>
int wordCount = 0;
int vowelCount = 0;
%}

%%
[a-zA-Z]+   {
                int vowels = 0;
                int i;
                for(i = 0; i < strlen(yytext); i++) {
                    if(yytext[i] == 'a' || yytext[i] == 'e' || yytext[i] == 'i' || yytext[i] == 'o' || yytext[i] == 'u' || yytext[i] == 'A' || yytext[i] == 'E' || yytext[i] == 'I' || yytext[i] == 'O' || yytext[i] == 'U') {
                        vowels++;
                    }
                }
                if(vowels >= 2) {
                    wordCount++;
                    vowelCount += vowels;
                    printf("Word: %s\n", yytext);
                }
            }

\n          {
                
                printf("Word count: %d\n", wordCount);
                printf("Total vowel count: %d\n", vowelCount);
            }
%%

int yywrap(){}

int main() {
    yyin = fopen("input.txt","r");

    yylex();
    return 0;
}
