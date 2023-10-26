%option noyywrap yylineno nounistd

%{
#include <duo1/duo.h>

#include "y.tab.h"

#ifdef __cplusplus
extern "C" int isatty(int);
#endif /* __cplusplus */

size_t yystrnprep(char *dst, char *src, size_t len);

size_t yystrnoff(const char *src, size_t len);

extern char *yypool;
%}

%%

[ \t\n\r]+ { ; }

print { return tPRINT; }

\"(\\.|[^"\\])*\" {
    char buf[1024] = {0};

    size_t buflen = yystrnprep(buf, yytext + 1, strlen(yytext) - 2);

    yylval.mSTRING = yypool + yystrnoff(buf, buflen);
    return tSTRING;
}

. { return yytext[0]; }

%%

char *yypool = NULL;

size_t yystrnprep(char *dst, char *src, size_t len) {
    size_t newlen = 0;

    for (size_t i = 0; i < len; ) {
        char c = src[i++];

        switch (c) {
        case '\\':
            c = src[i++];

            switch (c) {
            case '0': c = '\0'; break;
            case 'n': c = '\n'; break;
            case 't': c = '\t'; break;
            case 'r': c = '\r'; break;
            }
            break;
        }

        if (c == '\0')
            break;

        dst[newlen++] = c;
    }

    dst[newlen] = 0;

    return newlen;
}

size_t yystrnoff(const char *src, size_t len) {
    char *it = yypool;

    while (it[0] && memcmp(it, src, len) != 0) {
        it += strlen(it);
        it += 1;
    }

    memcpy(it, src, len);

    it[len] = 0;

    return it - yypool;
}