SRCDIR := sources

# Begin user settings

INCLUDE_DIRECTORIES := includes

CFLAGS := -Wall -g

# End user settings

CFLAGS += $(addprefix -I, $(INCLUDE_DIRECTORIES))

YFLAGS += -d

SRCS := $(shell find $(SRCDIR) -name "*.c")
SRCS += $(SRCDIR)/duo/y.tab.o $(SRCDIR)/duo/lex.yy.o

OBJS := $(patsubst %.c, %.o, $(SRCS))

.SUFFIXES:

.PHONY: all clean

all: duo
	./$< examples/example.duo

duo: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.c: %.y
	$(YACC) -o $@ $(YFLAGS) $^

%.c: %.l
	$(LEX) -o $@ $(LFLAGS) $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $^
