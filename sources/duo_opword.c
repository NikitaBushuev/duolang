#include <duo1/duo.h>

void duo_opword_write(const duo_opword_t *self, FILE *file) {
    fwrite(self, sizeof(duo_opword_t), 1, file);
}