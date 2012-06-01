CC=gcc
CFLAGS=-Wall #-Wextra -pedantic -Werror
PROGNAME=m00conv

all: main.o m00util.o m00convert.o
	$(CC) $^ $(CFLAGS) -o $(PROGNAME)

debug: CFLAGS += -DEBUG

debug: clean all

clean:
	rm -f m00conv main.o m00util.o m00convert.o
