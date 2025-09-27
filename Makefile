CC = clang
CFLAGS = -std=c99 -Wall -pedantic -fPIC -I./src
LDFLAGS = -shared -fPIC

SRC = src
OBJ = obj
LIB = lib
BIN = bin

LIBLIST = $(LIB)/liblist.so
LIBARRAY = $(LIB)/libarray.so
LIBMEM = $(LIB)/libmem.so

OBJLIST = $(OBJ)/list.o
OBJARRAY = $(OBJ)/array.o
OBJMEM = $(OBJ)/mem.o
OBJTEST0 = $(OBJ)/test0.o

TEST0 = $(BIN)/test0

all: $(OBJLIST) $(OBJARRAY) $(OBJMEM) $(LIBLIST) $(LIBARRAY) $(LIBMEM) $(TEST0)

$(OBJ) $(LIB) $(BIN):
	mkdir -p $@

$(OBJLIST): $(SRC)/list.c $(SRC)/list.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/list.c -o $(OBJLIST)

$(OBJARRAY): $(SRC)/array.c $(SRC)/array.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/array.c -o $(OBJARRAY)

$(OBJMEM): $(SRC)/mem.c $(SRC)/mem.h | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/mem.c -o $(OBJMEM)

$(LIBLIST): $(OBJLIST) | $(LIB)
	$(CC) $(LDFLAGS) -o $(LIBLIST) $(OBJLIST)

$(LIBARRAY): $(OBJARRAY) | $(LIB)
	$(CC) $(LDFLAGS) -o $(LIBARRAY) $(OBJARRAY)

$(LIBMEM): $(OBJMEM) | $(LIB)
	$(CC) $(LDFLAGS) -o $(LIBMEM) $(OBJMEM)

$(OBJTEST0): $(SRC)/test0.c | $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)/test0.c -o $(OBJTEST0)

$(TEST0): $(OBJTEST0) $(LIBLIST) $(LIBARRAY) $(LIBMEM) | $(BIN)
	$(CC) -o $(TEST0) $(OBJTEST0) -L$(LIB) -llist -larray -lmem

clean:
	-rm -f $(OBJ)/*.o

cleaner:
	-rm -f $(OBJ)/*.o $(LIB)/*.so $(BIN)/*
