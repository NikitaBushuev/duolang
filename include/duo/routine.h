#pragma once

#include <stdio.h>

#include "type.h"
#include "byte.h"

#include "opcode.h"
#include "state.h"

typedef void (*duo_routine_t)(duo_state_t *_state, FILE *_fp);

extern duo_type_t g_duo_routinetype;

extern duo_routine_t g_duo_routines[__DUO_OPCODES_LEN];

void duo_routine_aconst(duo_state_t *_state, FILE *_fp);

void duo_routine_sconst(duo_state_t *_state, FILE *_fp);

void duo_routine_push(duo_state_t *_state, FILE *_fp);

void duo_routine_pop(duo_state_t *_state, FILE *_fp);

void duo_routine_import(duo_state_t *_state, FILE *_fp);

void duo_routine_call(duo_state_t *_state, FILE *_fp);

void duo_routine_attr(duo_state_t *_state, FILE *_fp);

void duo_routine_assign(duo_state_t *_state, FILE *_fp);
