#include <duo1/duo.h>

#include <assert.h>

#include <stdio.h>

int yyparse(void);

extern FILE *yyin, *yyout;

extern char *yypool;

int main(int argc, char **argv) {
	assert(argc == 2);

	char pool[1024] = {0};

	yyin = fopen(argv[1], "rb");
	assert(yyin != NULL);

	yyout = tmpfile();
	assert(yyout != NULL);

	yypool = pool;

	assert(yyparse() == 0);

	fclose(yyin);

	fseek(yyout, 0, SEEK_SET);

	unsigned char bytes[1024] = {0};

	duo_type_t types[128] = {0};

	duo_state_t state = {0};

	duo_state_create(&state, bytes, types);

	duo_opword_t buf[BUFSIZ] = {0};

	size_t count = 0;

	while ((count = fread(buf, sizeof(duo_opword_t), BUFSIZ, yyout)) > 0) {
		for (size_t i = 0; i < count; ++i) {
			const duo_opword_t word = buf[i];

			const duo_routine_t routine = g_duo_routines[word.opcode];

			assert(routine != NULL);

			routine(&state, word);
		}
	}

	return 0;
}