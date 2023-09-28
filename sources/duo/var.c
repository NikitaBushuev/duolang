#include <duo.h>

duo_type_t g_duo_vartype = {
    .name = "var",
    .size = sizeof(duo_var_t),

    .operator = duo_var_operator,
};

void duo_var_operator (
    duo_operator_t op,
    duo_byte_t *bytes,
    duo_type_t *types,
    size_t len
) {
    switch (op) {
    case DUO_OPERATOR_ASSIGN:
        break;
    
    case DUO_OPERATOR_CALL:
        break;
    
    case DUO_OPERATOR_ATTRIBUTE:
        break;

    default:
        break;
    }
}