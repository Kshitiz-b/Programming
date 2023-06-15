%{
#include "y.tab.h"
%}

%%

[A-Z]{5}[0-9]{4}[A-Z]   { yylval = yytext; return PAN; }
.|\n
%%

int yywrap() {
    return 1;
}
