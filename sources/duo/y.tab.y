%locations

%{
#include <duo.h>

#include <stddef.h>
#include <stdint.h>

#include <stdio.h>

void yyerror(const char *msg);
int yylex(void);

extern FILE *yyout;

extern int yylineno;
%}

%union {
    size_t OFFSET;
    size_t COUNT;
}

%token
    <OFFSET> tVARIABLE
    <OFFSET> tSTRING

%type
    <COUNT> expressions

%right '='

%left '.'

%start program

%%

program
    : expressions {
        fputc(DUO_OPCODE_POP, yyout);
        fwrite(&$1, 1, sizeof($1), yyout);
    }
    ;

expressions
    : expressions expression {
        ++$$;
    }
    | {
        $$ = 0;
    }
    ;

literal
    : tVARIABLE {
        fputc(DUO_OPCODE_VARCONST, yyout);
        fwrite(&$1, 1, sizeof($1), yyout);
    }
    | tSTRING {
        fputc(DUO_OPCODE_STRCONST, yyout);
        fwrite(&$1, 1, sizeof($1), yyout);
    }
    ;

expression
    : literal {
        fputc(DUO_OPCODE_PUSH, yyout);
    }
    | expression '(' expressions ')' {
        fprintf(yyout, "%c%c%c",
            DUO_OPCODE_OPERATOR, DUO_OPERATOR_CALL, $3);
    }
    | expression '.' expression {
        fprintf(yyout, "%c%c%c",
            DUO_OPCODE_OPERATOR, DUO_OPERATOR_ATTRIBUTE, 1);
    }
    | expression '=' expression {
        fprintf(yyout, "%c%c%c",
            DUO_OPCODE_OPERATOR, DUO_OPERATOR_ASSIGN, 1);
    }
    | '(' expression ')' {
        ;
    }
    ;

%%

void yyerror(const char *msg) {
    const char *fmt = "duo: error: %d: %s\n";

    fprintf(stderr, fmt, yylineno, msg);
}