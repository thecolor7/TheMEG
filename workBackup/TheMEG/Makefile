#if not working, my module 2 was fixed by changing -l. to -lm
CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:					testget testremove puttest applytest

list.o:				list.c list.h
							gcc $(CFLAGS) -c list.c

#add one of these per test file and make sure each test is listed in all

# lget() Make files
testget.o:		testget.c list.h
							gcc $(CFLAGS) -c testget.c

testget:			testget.o list.o
							gcc $(CFLAGS) testget.o list.o -o testget

# lremove() Make files
testremove.o: testremove.c list.h
							gcc $(CFLAGS) -c testremove.c

testremove:   testremove.o list.o
							gcc $(CFLAGS) testremove.o list.o -o testremove

# lput() Make files
puttest.o:		puttest.c list.h
							gcc $(CFLAGS) -c puttest.c

puttest:			puttest.o list.o
							gcc $(CFLAGS) puttest.o list.o -o puttest
# lapply() Make files
applytest.o:	applytest.c list.h
							gcc $(CFLAGS) -c applytest.c

applytest:		applytest.o list.o
							gcc $(CFLAGS) applytest.o list.o -o applytest

clean:
							rm -rf *.o
