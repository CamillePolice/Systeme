# Link
#
OBJ=./obj
LIB=./lib
BIN=./bin
SRC=./src
CFLAGS += -ggdb -Wall
HFILES=-I./include

all: bin/lecture bin/audioclient bin/audioserver

bin/lecture:	$(OBJ)/lecture.o $(OBJ)/audio.o
	gcc -o $@ $^
bin/audioclient:	$(OBJ)/audioclient.o $(OBJ)/audio.o $(OBJ)/filters.o
		gcc -o $@ $^
bin/audioserver:	$(OBJ)/audioserver.o $(OBJ)/audio.o
				gcc -o $@ $^
# macro interne à make
# $@ : fait référence à la cible.
# $^ : contient tous les composants d'une règle.


obj/lecture.o: $(SRC)/lecture.c
	gcc -o $(OBJ)/lecture.o $(HFILES) -c -Wall $(SRC)/lecture.c

obj/audioclient.o: $(SRC)/audioclient.c
	gcc -o $(OBJ)/audioclient.o $(HFILES) -c -Wall $(SRC)/audioclient.c

obj/audioserver.o: $(SRC)/audioserver.c
	gcc -o $(OBJ)/audioserver.o $(HFILES) -c -Wall $(SRC)/audioserver.c

obj/audio.o: $(LIB)/audio.c
		gcc -o $(OBJ)/audio.o $(HFILES) -c -Wall $(LIB)/audio.c

obj/filters.o: $(LIB)/filters.c
		gcc -o $(OBJ)/filters.o $(HFILES) -c -Wall $(LIB)/filters.c
#
# Listing creation in pdf
#

listing:
# To be completed

#
# Remove files
#

clean :
	rm -rf obj/*.o bin/*
#
# Test the functionality
#

test :
# To be completed
