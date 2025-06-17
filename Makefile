
CC = gcc


CFLAGS = -Wall -g -Iinclude


SRC = src/playlist.c
OBJ = main.o src/playlist.o


EXEC = Lab_5


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)


main.o: main.c include/playlist.h
	$(CC) $(CFLAGS) -c main.c


src/playlist.o: src/playlist.c include/playlist.h
	$(CC) $(CFLAGS) -c src/playlist.c -o src/playlist.o


clean:
	rm -f $(OBJ) $(EXEC)




