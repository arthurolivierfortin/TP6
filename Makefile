CC = gcc
CFLAGS = -g -w -Wall
CXXFLAGS=-Ilib -Isrc -Itest
VPATH=lib:src:test
OBJ := exe

main: main.o util.o
	$(CC) $(CFLAGS) -o main main.o util.o

test_perso: test_perso.o
	$(CC) $(CFLAGS) -o test_perso test_perso.o

test_perso.o: ./test/test_perso.c ./test/test_perso.h
	$(CC) $(CFLAGS) -c ./test/test_perso.c

test_unit: test_unit.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o

test_unit.o: ./test/test_unit.c ./src/util.h
	$(CC) $(CFLAGS) -c ./test/test_unit.c

util.o: ./src/util.h ./src/util.c
	$(CC) $(CFLAGS) -c ./src/util.c -o util.o

main.o: ./src/util.h ./src/util.c ./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c -o main.o

	

clean:
	rm -f *.o main test_unit