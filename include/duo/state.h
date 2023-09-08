#pragma once

typedef struct duo_state_t duo_state_t;

#include "type.h"
#include "byte.h"

#include "alpha.h"
#include "string.h"

struct duo_state_t {
	duo_type_t *_M_tp;
	duo_byte_t *_M_bt;

	duo_type_t _M_rt;

	union {
		duo_alpha_t a;
		duo_string_t s;
	} _M_rv;

	char *_M_pool;
};

extern duo_type_t g_duo_statetype;

void duo_state_create(duo_state_t *_state, duo_type_t *_types, void *_bytes);

void duo_state_execute(duo_state_t *_state, const char *_path);