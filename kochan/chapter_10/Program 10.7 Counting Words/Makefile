#gcc program-source-code.c -o executable-file-name
#gcc main.c -o test1

# Put your source files here (or *.c, etc)
SRCS=main.c

# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=test

CC=gcc
CFLAGS=-I.
DEPS= main.h
OBJ= main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#main: $(OBJ)
$(PROJ_NAME): $(OBJ)
	$(CC) -lm -o $@ $^ $(CFLAGS)
