CC=gcc
CFLAGS=-Wall #-Wextra -pedantic -Werror
PROGNAME=m00conv

.PHONY: m00conv_debug clean

m00conv: main.o m00util.o m00convert.o
	$(CC) $^ $(CFLAGS) -o $(PROGNAME)

m00conv_debug: PROGNAME = m00conv_debug

m00conv_debug: CFLAGS += -DEBUG

m00conv_debug: clean m00conv

clean:
	rm -f m00conv main.o m00util.o m00convert.o m00conv_debug
