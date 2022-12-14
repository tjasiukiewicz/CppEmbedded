.PHONY := clean

CC := gcc

CFLAGS := -Wall -Wextra -pedantic
LDFLAGS :=
OBJS := main.o foo.o

WRAP_CFLAGS := $(CFLAGS)
WRAP_LDFLAGS := $(LD_FLAGS) -Wl,-wrap=foo
WRAP_OBJS := main.o
WRAP_SRCDIR := tests

main: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

wrap: $(WRAP_OBJS)
	$(CC) $(WRAP_LDFLAGS) -o main $^ $(WRAP_SRCDIR)/foo.c -I$(WRAP_SRCDIR)

clean:
	@rm -f main $(OBJS) $(WRAP_OBJS) > /dev/null 2>&1
