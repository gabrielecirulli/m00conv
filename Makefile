CC=gcc
CFLAGS=-Wall

m00conv: main.o m00util.o
	$(CC) $^ -o $@

clean:
	rm -f m00conv main.o m00util.o
