CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: 					testmfile

#should handle all of the .o files
%.o:					%.c %.h
							gcc $(CFLAGS) -c $<

#need one of these per test
testmfile:		hash.o queue.o testmfile.o
							gcc $(CFLAGS) hash.o queue.o testmfile.o -o $@

clean:
							rm -rf *.o
