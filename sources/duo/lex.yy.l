%option noyywrap yylineno nounistd

%{
#include <duo.h>

#include "y.tab.h"

size_t yynstr(const char *str, size_t len);
%}

%%

[ \t\n\r]+ {
    ;
}

#.* {
    ;
}

[_a-zA-Z]+ {
    yylval.OFFSET = yynstr(yytext, strlen(yytext));
    return tVARIABLE;
}

\"(\\.|[^"\\])*\" {
    yylval.OFFSET = yynstr(yytext + 1, strlen(yytext) - 2);
    return tSTRING;
}

. {
    return *yytext;
}

%%

char *yypool = NULL;

size_t yynstr(const char *str, size_t len) {
    char *pc = yypool;

    size_t off = 0;

    while (*pc) {
        pc += strlen(pc) + 1;
    }

    strncat(pc, str, len);

    return pc - yypool;
}