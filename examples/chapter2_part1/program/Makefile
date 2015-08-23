CC=gcc
CFLAGS=-Wall

PRE_PROCESS=hello include swap
ASSEMBLY=stupid_add
OBJECT=hello

all: ${PRE_PROCESS} ${ASSEMBLY} ${OBJECT}

${PRE_PROCESS}:
	gcc -E $@.c -o $@.out

${ASSEMBLY}:
	gcc -S $@.c -O0 -o $@_O0.s
	gcc -S $@.c -O1 -o $@_O1.s

${OBJECT}:
	gcc -S $@.c -o $@.s
	as $@.s -o $@.o 

clean:
	rm -f *.out *.s *.o swap
