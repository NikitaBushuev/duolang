#pragma once

typedef struct duo_map_t duo_map_t;

#include "type.h"

struct duo_map_t {
    size_t _M_value_size;
    size_t *_M_keys;
    void *_M_values;
    size_t _M_cap;
};

extern duo_type_t g_duo_maptype;

void *duo_map_insert(duo_map_t *_map, size_t _key, void *_value);

void duo_map_erase(duo_map_t *_map, size_t _key);

void *duo_map_find(duo_map_t *_map, size_t _key);