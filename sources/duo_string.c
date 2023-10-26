#include <duo1/duo.h>

#include <stdio.h>

const duo_type_t g_duo_stringtype = {
    .size = sizeof(duo_string_t),

    .write = (void (*)(const void *, FILE *)) duo_string_write,
};

void duo_string_write(const duo_string_t *self, FILE *file) {
    fputs(self[0], file);
}