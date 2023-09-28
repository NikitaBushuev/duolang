#pragma once

#include <stddef.h>

#include <duo/operator.h>
#include <duo/byte.h>

typedef struct _duo_type duo_type_t;

struct _duo_type {
    const char *name;
    size_t size;

    void (*operator) (
        duo_operator_t op,
        duo_byte_t *bytes,
        duo_type_t *types,
        size_t len
    );
};

