#pragma once

typedef enum DUO_OPCODE DUO_OPCODE;

enum DUO_OPCODE {
    DUO_OPCODE_UNDEF = 0,

    DUO_OPCODE_VARCONST,
    DUO_OPCODE_STRCONST,

    DUO_OPCODE_PUSH,
    DUO_OPCODE_POP,

    DUO_OPCODE_OPERATOR,
};

typedef unsigned char duo_opcode_t;

const char *duo_opcode_str(duo_opcode_t opcode);