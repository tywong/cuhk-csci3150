CC=gcc
CFLAGS=
EXE=q1 q2 q3 q4 alice bob

all: ${EXE}

alice: person.c
	gcc -Wall -o alice $<

bob: person.c
	gcc -Wall -o bob $<

clean:
	/bin/rm -f ${EXE}
