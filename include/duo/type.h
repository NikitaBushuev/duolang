#pragma once

#include <stddef.h>

typedef struct duo_type_t duo_type_t;

#include "type.h"
#include "size.h"
#include "string.h"

struct duo_type_t {
	const duo_string_t _M_name;

	duo_size_t _M_size;
};

extern duo_type_t g_duo_typetype;