#pragma once

typedef struct _duo_state duo_state_t;

#include "duo_type.h"

#include "duo_opword.h"

struct _duo_state {
    unsigned char *bt;
    duo_type_t *tp;
};

void duo_state_create(duo_state_t *state, void *bytes, duo_type_t *types);

void duo_state_push(duo_state_t *state, const void *value, const duo_type_t *type);

void duo_state_pop(duo_state_t *state);