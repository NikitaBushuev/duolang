#pragma once

typedef enum DUO_OPERATOR DUO_OPERATOR;

enum DUO_OPERATOR {
    DUO_OPERATOR_UNDEF = 0,

    DUO_OPERATOR_CALL,

    DUO_OPERATOR_ATTRIBUTE,

    DUO_OPERATOR_ASSIGN,
};

typedef unsigned char duo_operator_t;