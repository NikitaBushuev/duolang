#pragma once

#include "duo_state.h"

#include "duo_opword.h"

typedef void (*duo_routine_t)(duo_state_t *state, duo_opword_t word);

extern const duo_routine_t g_duo_routines[DUO_NUM_OF_OPCODES];

void duo_routine_sconst(duo_state_t *state, duo_opword_t word);

void duo_routine_print(duo_state_t *state, duo_opword_t word);

void duo_routine_pop(duo_state_t *state, duo_opword_t word);
