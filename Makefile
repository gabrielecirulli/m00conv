CFLAGS=-std=c99 -Wall -Wall -pedantic -Werror -iquote inc

.PHONY: clean

m00conv: src/main.o src/m00util.o src/m00convert.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c Makefile inc/*.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f src/*.o m00conv