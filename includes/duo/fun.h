#pragma once

#include <duo/type.h>

typedef void (*duo_fun_t) (
    void *bytes,
    duo_type_t *types,
    size_t len
);

extern duo_type_t g_duo_funtype;

void duo_fun_operator (
    duo_operator_t op,
    void *bytes,
    duo_type_t *types,
    size_t len
);