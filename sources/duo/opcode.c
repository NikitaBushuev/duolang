#include <duo.h>

const char *duo_opcode_str(duo_opcode_t opcode) {
    switch (opcode) {
    case DUO_OPCODE_VARCONST:
        return "vconst";
    case DUO_OPCODE_STRCONST:
        return "sconst";
    case DUO_OPCODE_PUSH:
        return "push";
    case DUO_OPCODE_POP:
        return "pop";
    case DUO_OPCODE_OPERATOR:
        return "operator";
    default:
        break;
    }
    return "undef";
}