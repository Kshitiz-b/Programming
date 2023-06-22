%{
#include "pan.tab.h"
%}

%%
[A-Z]{5}[0-9]{4}[A-Z]    { yylval.str = strdup(yytext); return PAN_NUMBER; }
.|\n                     { /* ignore other characters */ }
%%

int yywrap() {
    return 1;
}
