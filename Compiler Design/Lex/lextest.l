%{
    #include<stdio.h>
    int vowel_count=0;
    int con_count;
%}
%%
[aeiou] {vowel_count++;}
[a-z] {con_count++;}
%%
int yywrap(){
    return 1;
}
int main(){
    printf("enter the string: ");
    yylex();
    printf("Vowel Count: %d\n", vowel_count);
    printf("Consonant Count: %d", con_count);
    return 0;
}