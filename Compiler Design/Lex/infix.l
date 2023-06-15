%{
#include "y.tab.h"
%}

%%

[0-9]+               { yylval = atoi(yytext); return NUMBER; }
[+\-*/()^]           { return yytext[0]; }
[ \t\n]              ; /* Ignore whitespace and newline characters */
.                    { /* Ignore any other characters */ }

%%

int yywrap() {
    return 1;
}
