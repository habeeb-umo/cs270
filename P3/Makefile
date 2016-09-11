# Simple Makefile for FLOAT Assignment

# These are defined so that on a different system only these definitions
# need to change if gcc and rm are actually in different locations
# The rest of the Makefile need not change

RM   = rm
GCC  = gcc

CFLAGS  = -std=c11 -g -Wall -c
LDFLAGS = -std=c11 -g

testFlt32: flt32.o testFlt32.o
	${GCC} ${LDFLAGS} -o testFlt32 flt32.o testFlt32.o

flt32.o: flt32.h flt32.c
	${GCC} ${CFLAGS} flt32.c

testFlt32.o: flt32.h testFlt32.c
	${GCC} ${CFLAGS} testFlt32.c

clean:
	${RM} -f *.o testFlt32


