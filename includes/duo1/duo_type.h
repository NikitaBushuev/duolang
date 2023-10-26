#pragma once

#include <stdio.h>

typedef struct _duo_type duo_type_t;

struct _duo_type {
    size_t size;

    void (*write)(const void *self, FILE *file);
};