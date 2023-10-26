#pragma once

typedef const char *duo_string_t;

#include "duo_type.h"

extern const duo_type_t g_duo_stringtype;

void duo_string_write(const duo_string_t *self, FILE *file);