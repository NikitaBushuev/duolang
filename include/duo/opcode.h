#pragma once

enum {
	DUO_OP_UNDEFINED,

	DUO_OP_ACONST,
	DUO_OP_SCONST,

	DUO_OP_PUSH,
	DUO_OP_POP,

	DUO_OP_IMPORT,

	DUO_OP_CALL,
	DUO_OP_ATTR,

	DUO_OP_ASSIGN,

	__DUO_OPCODES_LEN,
};

const char *duo_opcode_string(int op);