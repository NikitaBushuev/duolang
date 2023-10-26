#include <duo1/duo.h>

#include <string.h>

void duo_state_create(duo_state_t *state, void *bytes, duo_type_t *types) {
    state->bt = (unsigned char *) bytes;
    state->tp = types;

    state->tp->size = 1;
}

void duo_state_push(duo_state_t *state, const void *value, const duo_type_t *type) {
    state->bt += state->tp->size;
    state->tp += 1;

    memcpy(state->bt, value, type->size);

    state->tp[0] = type[0];
}

void duo_state_pop(duo_state_t *state) {
    state->tp -= 1;
    state->bt -= state->tp->size;
}