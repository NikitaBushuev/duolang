#include <duo1/duo.h>

#include <assert.h>

const duo_routine_t g_duo_routines[DUO_NUM_OF_OPCODES] = {
    [DUO_OPCODE_UNDEFINED] = NULL,

    [DUO_OPCODE_SCONST] = duo_routine_sconst,

    [DUO_OPCODE_PRINT] = duo_routine_print,

    [DUO_OPCODE_POP] = duo_routine_pop,
};

void duo_routine_sconst(duo_state_t *state, duo_opword_t word) {
    duo_state_push(state, &word._u_string, &g_duo_stringtype);
}

void duo_routine_print(duo_state_t *state, duo_opword_t word) {
    assert(state->tp->write != NULL);

    state->tp->write(state->bt, stdout);
}

void duo_routine_pop(duo_state_t *state, duo_opword_t word) {
    duo_state_pop(state);
}