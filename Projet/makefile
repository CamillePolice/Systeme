# Link
#
OBJ=./obj
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
# To be completed
	gcc -o $(OBJ)/lecture.o $(HFILES) -c -Wall $(SRC)/lecture.c

obj/audioclient.o: $(SRC)/audioclient.c
# To be completed
	gcc -o $(OBJ)/audioclient.o $(HFILES) -c -Wall $(SRC)/audioclient.c

obj/audioserver.o: $(SRC)/audioserver.c
# To be completed
	gcc -o $(OBJ)/audioserver.o $(HFILES) -c -Wall $(SRC)/audioserver.c

obj/audio.o: $(SRC)/audio.c
	# To be completed
		gcc -o $(OBJ)/audio.o $(HFILES) -c -Wall $(SRC)/audio.c

obj/filters.o: $(SRC)/filters.c
# To be completed
	gcc -o $(OBJ)/filters.o $(HFILES) -c -Wall $(SRC)/filters.c
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
