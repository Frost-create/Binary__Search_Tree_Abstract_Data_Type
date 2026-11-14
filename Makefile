.PHONY: all
all: unique 

CFLAGS = -Wall -Werror -gdwarf-4

unique.c: unique.c
	clang -c $(CFLAGS) unique.c

tree.o: tree.c 
	clang -c $(CFLAGS) tree.c 

unique: unique.o tree.o
	clang unique.o tree.o -o unique

