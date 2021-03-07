# Programs and utilities used in the building process
GCC          := gcc
CFLAGS       := -Wextra

# Directories
SRCDIR       := src
BUILDDIR     := build
INSTALLDIR   := /usr/local/bin/

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

install: $(ELFTARGET)
	cp $(ELFTARGET) $(INSTALLDIR)

uninstall:
	rm $(INSTALLDIR)/$(ELFTARGET)

clean:
	rm -f $(ELFTARGET) $(OBJS)
	rmdir build

.PHONY: all clean install uninstall
