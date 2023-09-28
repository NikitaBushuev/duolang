#include <duo.h>

duo_type_t g_duo_funtype = {
    .name = "fun",
    .size = sizeof(duo_fun_t),

    .operator = duo_fun_operator,
};

void duo_fun_operator (
    duo_operator_t op,
    void *bytes,
    duo_type_t *types,
    size_t len
) {
    switch (op)
    {
    case DUO_OPERATOR_CALL:
        ((duo_fun_t) bytes)
            (bytes + types->size, types + 1, len - 1);
        break;

    default:
        break;
    }
}