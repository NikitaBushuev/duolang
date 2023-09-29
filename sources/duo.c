#include <duo.h>

#include <assert.h>

#include <stdio.h>

int main(int argc, char **argv) {
    assert(argc == 2);

    duo_state_t state = {0};

    duo_state_execute(&state, argv[1]);

    puts("finished");

    return 0;
}
