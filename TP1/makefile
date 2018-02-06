# Link
#
OBJ=./obj
BIN=./bin
SRC=./src
CFLAGS += -ggdb
HFILES=-I./include

all: bin/shell1 bin/shell2 bin/shell3 bin/shelltest

bin/shell1:	$(OBJ)/shell1.o
	gcc -o $@ $^

bin/shell2: $(OBJ)/shell2.o
	gcc -o $@ $^

bin/shell3: $(OBJ)/shell3.o
	gcc -o $@ $^

bin/shelltest: $(OBJ)/shelltest.o
	gcc -o $@ $^

# Objets of TP Lists
#

obj/shell1.o: $(SRC)/shell1.c
# To be completed
	gcc -o $(OBJ)/shell1.o $(HFILES) -c $(SRC)/shell1.c

obj/shell2.o: $(SRC)/shell2.c
	gcc -o $(OBJ)/shell2.o $(HFILES) -c $(SRC)/shell2.c

obj/shell3.o: $(SRC)/shell3.c
	gcc -o $(OBJ)/shell3.o $(HFILES) -c $(SRC)/shell3.c

obj/shelltest.o: $(SRC)/shelltest.c
	gcc -o $(OBJ)/shelltest.o $(HFILES) -c $(SRC)/shelltest.c


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
