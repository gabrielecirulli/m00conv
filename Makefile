CC=gcc
CFLAGS=-Wall
PROGNAME=m00conv

all: main.o m00util.o
	$(CC) $^ $(CFLAGS) -o $(PROGNAME)

debug: CFLAGS += -DEBUG

debug: clean all

clean:
	rm -f m00conv main.o m00util.o
