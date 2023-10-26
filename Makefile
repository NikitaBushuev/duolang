SRCDIR := sources

# Begin user settings

INCLUDE_DIRECTORIES := includes

CFLAGS := -Wall -g

# End user settings

CFLAGS += $(addprefix -I, $(INCLUDE_DIRECTORIES))

YFLAGS += -d

SRCS := $(wildcard $(SRCDIR)/*.c) $(SRCDIR)/y.tab.c $(SRCDIR)/lex.yy.c
OBJS := $(patsubst %.c, %.o, $(SRCS))

.SUFFIXES:

.PHONY: all clean

all: duo
	./$< examples/example.duo

clean:
	$(RM) $(OBJS)

duo: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.c: %.y
	$(YACC) -o $@ $(YFLAGS) $^

%.c: %.l
	$(LEX) -o $@ $(LFLAGS) $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $^
