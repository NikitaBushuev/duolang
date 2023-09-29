#include <duo.h>

#include <assert.h>

#include <string.h>

#include <stdio.h>

#define DUO_BYTES_LEN 1024
#define DUO_TYPES_LEN 128

int yyparse(void);

extern FILE *yyin, *yyout;

extern char *yypool;

void duo_state_execute(duo_state_t *state, const char *path) {
    yyin = fopen(path, "rb");
    assert(yyin != NULL);

    yyout = tmpfile();
    assert(yyout != NULL);

    char pool[1024] = {0};

    yypool = pool;

    assert(yyparse() == 0);

    fclose(yyin);

    FILE *fp = yyout;

    fseek(fp, 0, SEEK_SET);

    duo_byte_t bytes[DUO_BYTES_LEN] = {0}, *bt = NULL;
    duo_type_t types[DUO_TYPES_LEN] = {0}, *tp = NULL;

    types[0].size = 1;

    bt = bytes + 1;
    tp = types + 1;

    duo_type_t rt;

    union {
        duo_var_t var;
        duo_str_t str;
    } rv;

    size_t rz = 0;

    int op = 0;

    while ((op = fgetc(fp)) != -1) {
        printf("0x%.2x %8s", op, duo_opcode_str(op));

        switch (op) {
        case DUO_OPCODE_VARCONST:
            fread(&rz, 1, sizeof(rz), fp);

            rt = g_duo_vartype;

            rv.var = pool + rz;

            printf("\t%d\t\"%s\"", rz, rv.var);
            break;

        case DUO_OPCODE_STRCONST:
            fread(&rz, 1, sizeof(rz), fp);

            rt = g_duo_strtype;

            rv.str = pool + rz;

            printf("\t%d\t\"%s\"", rz, rv.str);
            break;
        
        case DUO_OPCODE_PUSH:
            bt += tp->size;
            tp += 1;

            memcpy(bt, &rv, rt.size);
            memcpy(tp, &rt, sizeof(rt));

            printf("\t1\t<%s>", rt.name);
            break;
        
        case DUO_OPCODE_POP:
            fread(&rz, 1, sizeof(rz), fp);

            printf("\t%d", rz);

            for (size_t i = 0; i < rz; ++i) {
                assert(tp > types);
                assert(bt > bytes);

                printf("\t<%s>", tp->name);

                tp -= 1;
                bt -= tp->size;
            }
            break;

        case DUO_OPCODE_OPERATOR:
            op = fgetc(fp);
            rz = fgetc(fp);

            for (size_t i = 0; i < rz; ++i) {
                tp -= 1;
                bt -= tp->size;
            }

            printf("\t<%s>", tp->name);

            assert(tp->operator != NULL);

            tp->operator(op, bt, tp, rz + 1);
            break;

        default:
            assert(0 && "undefined opcode");
            break;
        }
        printf("\n");
    }

    fclose(fp);
}