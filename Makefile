# Programs and utilities used in the building process
GCC          := gcc
CFLAGS       := -Wextra

# Directories
SRCDIR       := src
BUILDDIR     := build

# Files to compile.
SRCS         := $(wildcard $(SRCDIR)/*.c)
OBJS         := $(SRCS:.c=.o)

# Executable
ELFTARGET    := $(BUILDDIR)/pso-calc

all: $(ELFTARGET)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

$(ELFTARGET): $(BUILDDIR) $(SRCS)
	$(GCC) $(SRCS) $(CFLAGS) -o $(ELFTARGET)

$(BUILDDIR):
	mkdir build

clean:
	rm -f $(ELFTARGET) $(OBJS)
	rmdir build

.PHONY: all clean run
