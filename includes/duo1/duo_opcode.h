#pragma once

enum {
    DUO_OPCODE_UNDEFINED = 0,

    DUO_OPCODE_SCONST,

    DUO_OPCODE_PRINT,

    DUO_OPCODE_POP,

    DUO_NUM_OF_OPCODES,
};

typedef unsigned char duo_opcode_t;