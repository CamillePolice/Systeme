# Link
#
OBJ=./obj
BIN=./bin
SRC=./src
CFLAGS += -ggdb
HFILES=-I./include

all: bin/lecture

bin/lecture:	$(OBJ)/lecture.o
	gcc -o $@ $^

# Objets of TP Lists
#

obj/lecture.o: $(SRC)/lecture.c
# To be completed
	gcc -o $(OBJ)/lecture.o $(HFILES) -c $(SRC)/lecture.c

#
# Listing creation in pdf
#

listing:
# To be completed

#
# Remove files
#

clean :
# To be completed
	rm -rf obj/*.o bin/*
#
# Test the functionality
#

test :
# To be completed
