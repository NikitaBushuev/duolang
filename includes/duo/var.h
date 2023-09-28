#pragma once

#include <duo/type.h>

typedef const char *duo_var_t;

void duo_var_operator (
    duo_operator_t op,
    duo_byte_t *bytes,
    duo_type_t *types,
    size_t len
);

extern duo_type_t g_duo_vartype;
