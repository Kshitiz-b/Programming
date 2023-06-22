%{
#include "infix.tab.h"
%}

%%

[ \t\n]       ; /* Ignore whitespace and newlines */

[0-9]+        { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]     { return yytext[0]; } /* Return operators and parentheses */
.             { return yytext[0]; } /* Return any other characters as is */

%%

int yywrap() {
    return 1;
}
