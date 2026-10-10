CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: 					testofhash

#should handle all of the .o files
%.o:					%.c %.h
							gcc $(CFLAGS) -c $<

#need one of these per test
testofhash:		hash.o queue.o testofhash.o
							gcc $(CFLAGS) hash.o queue.o testofhash.o -o $@

clean:
							rm -rf *.o
