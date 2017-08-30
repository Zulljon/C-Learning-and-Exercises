#gcc program-source-code.c -o executable-file-name
#gcc main.c -o test1

# Put your source files here (or *.c, etc)
SRCS=5_2.c

# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=test_5_2

CC=gcc
CFLAGS=-I.
DEPS=
OBJ=5_2.o 


all: 5_2 5_3 5_4 5_5 

clean: clean-exec clean-obj

clean-obj:
	rm -f 5_2.o 5_3.o 5_4.o 5_5.o

clean-exec:
	rm -f test_5_2 test_5_3 test_5_4 test_5_5

5_2:
	@echo "build 5.2"
	$(CC) -c -o 5_2.o 5_2.c $(DEPS) $(CFLAGS)
	$(CC) -lm -o test_5_2 5_2.o $(CFLAGS)

5_3:
	@echo "build 5.3"
	$(CC) -c -o 5_3.o 5_3.c $(DEPS) $(CFLAGS)
	$(CC) -lm -o test_5_3 5_3.o $(CFLAGS)

5_4:
	@echo "build 5.4"
	$(CC) -c -o 5_4.o 5_4.c $(DEPS) $(CFLAGS)
	$(CC) -lm -o test_5_4 5_4.o $(CFLAGS)

5_5:
	@echo "build 5.5"
	$(CC) -c -o 5_5.o 5_5.c $(DEPS) $(CFLAGS)
	$(CC) -lm -o test_5_5 5_5.o $(CFLAGS)
