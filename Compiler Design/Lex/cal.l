%{
    #include <stdio.h>
    int a, b, c;
%}
%%
[0-9]+[' '] {a = atoi(yytext);}
[0-9]+ {b = atoi(yytext); c = a+b;}
%%
int yywrap(){
    return 1;
}
int main()
{
    printf("Enter a and b: ");
    yylex();
    printf("The result is: %d", c);

    return 0;
}