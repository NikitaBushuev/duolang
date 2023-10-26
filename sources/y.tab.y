%locations

%{
#include <stdio.h>

#include <duo1/duo.h>

void yyerror(const char *msg);
int yylex(void);

extern FILE *yyout;

extern int yylineno;
%}

%union {
    duo_string_t mSTRING;
}

%token
    tPRINT

%token
    <mSTRING> tSTRING

%%

statements
    : statement statements
    |
    ;

statement
    : expression {
        const duo_opword_t word = {
            .opcode = DUO_OPCODE_POP,
        };

        duo_opword_write(&word, yyout);
    }
    ;

expression
    : '(' expression ')' {
        ;
    }
    | tPRINT '(' expression ')' {
        const duo_opword_t word = {
            .opcode = DUO_OPCODE_PRINT,
        };

        duo_opword_write(&word, yyout);
    }
    | tSTRING {
        const duo_opword_t word = {
            .opcode = DUO_OPCODE_SCONST,

            ._u_string = $1,
        };

        duo_opword_write(&word, yyout);
    }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "duo: error: %d: %s\n", yylineno, msg);
}
