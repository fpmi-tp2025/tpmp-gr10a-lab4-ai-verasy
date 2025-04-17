CC = gcc
CFLAGS = -Wall -Iincludes
LDFLAGS = -lsqlite3

SRC = src/main.c src/auth.c src/database.c src/farms.c src/furs.c src/auctions.c src/utils.c
OBJ = $(SRC:.c=.o)
BIN = bin/auction

all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean
