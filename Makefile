CFLAGS=-std=c99 -Wall -iquote inc

.PHONY: clean

m00conv: src/main.o src/m00util.o src/m00convert.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f src/*.o m00conv