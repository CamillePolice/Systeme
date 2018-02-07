# Link
#
OBJ=./obj
BIN=./bin
SRC=./src
CFLAGS += -ggdb

HFILES=-I./include
all: bin/tp3 bin/nettoie
bin/tp3:	$(OBJ)/tp3.o
# To be completed
	gcc -o $@ $^

bin/nettoie:	$(OBJ)/nettoie.o
# To be completed
	gcc -o $@ $^
#
# Objets of TP Lists
#

obj/tp3.o: $(SRC)/tp3.c
# To be completed
	gcc -o $(OBJ)/tp3.o $(HFILES) -c $(SRC)/tp3.c

obj/nettoie.o: $(SRC)/nettoie.c
# To be completed
	gcc -o $(OBJ)/nettoie.o $(HFILES) -c $(SRC)/nettoie.c

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
	rm -rf *.o
#
# Test the functionality
#

test :
# To be completed
