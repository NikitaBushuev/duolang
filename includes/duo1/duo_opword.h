#pragma once

#include <stddef.h>

typedef struct _duo_opword duo_opword_t;

#include "duo_opcode.h"

#include "duo_string.h"

struct _duo_opword {
    duo_opcode_t opcode;

    union {
        duo_string_t _u_string;
    };
};

void duo_opword_write(const duo_opword_t *self, FILE *file);
