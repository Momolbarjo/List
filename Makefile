CC = gcc
CFLAGS =  -I$(IDIR) 

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
all: list run

list:	$(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./list

clean:
	rm list
