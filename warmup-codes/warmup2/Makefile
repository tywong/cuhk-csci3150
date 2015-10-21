CC=gcc
CFLAGS=-Wall
EXE=q1 q2a q2b q3 q4 alice bob

all: ${EXE}

alice: person.o
	gcc -o alice person.o

bob: person.o
		gcc -o bob person.o

clean:
	/bin/rm -f *.o ${EXE}
