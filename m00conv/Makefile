CC=gcc
CFLAGS=-Wall #-Wextra -pedantic -Werror
PROGNAME=m00conv

.PHONY: clean

m00conv: main.o m00util.o m00convert.o
	$(CC) $^ $(CFLAGS) -o $(PROGNAME)

m00conv_d: PROGNAME = m00conv_d

m00conv_d: CFLAGS += -DEBUG

m00conv_d: clean m00conv

clean:
	rm -f m00conv main.o m00util.o m00convert.o m00conv_d
