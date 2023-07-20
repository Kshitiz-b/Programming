%{
    #include<stdio.h>

%}
%%
[cC][a-zA-Z]*[tT] {printf("%s", yytext);}
.
%%
int yywrap(){
    return 1;
}
int main(){
    printf("enter the string: ");
    yylex();
    return 0;
}