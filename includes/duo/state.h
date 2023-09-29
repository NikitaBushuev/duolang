#pragma once

typedef struct _duo_state duo_state_t;

#include <duo/type.h>
#include <duo/byte.h>

struct _duo_state {
    duo_byte_t *bt;
};

void duo_state_execute(duo_state_t *state, const char *path);