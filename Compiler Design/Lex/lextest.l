%{
    #include<stdio.h>
%}
%%
"hi" {printf("tu chutiya hai");}
.* {printf("tu chutiya nhi hai");} 
%%
int yywrap(){
    return 1;
}
int main(){
    printf("enter the string: ");
    yylex();
    return 0;
}