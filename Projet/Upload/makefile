# Link
#
OBJ=./obj
BIN=./bin
SRC=./src
CFLAGS += -ggdb -Wall
HFILES=-I./include

all: bin/lecture

bin/lecture:	$(OBJ)/lecture.o $(OBJ)/audio.o
	gcc -o $@ $^
# macro interne à make
# $@ : fait référence à la cible.
# $^ : contient tous les composants d'une règle.


obj/lecture.o: $(SRC)/lecture.c
# To be completed
	gcc -o $(OBJ)/lecture.o $(HFILES) -c -Wall $(SRC)/lecture.c

obj/audio.o: $(SRC)/audio.c
	# To be completed
		gcc -o $(OBJ)/audio.o $(HFILES) -c -Wall $(SRC)/audio.c
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
