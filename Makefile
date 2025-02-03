CC=gcc
CFLAGS=-I. -Wall

DEPS = process.h scheduler.h memory.h
OBJ = main.o scheduler.o memory.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

osim: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o osim 