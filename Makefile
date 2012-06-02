.PHONY: all bin/m00conv debug clean bin/m00conv_debug bin/clean copydebug

all: m00conv/m00conv

debug: clean m00conv/m00conv_d copydebug

clean: m00conv/clean

m00conv/m00conv:
	$(MAKE) -C m00conv m00conv

m00conv/m00conv_d:
	$(MAKE) -C m00conv m00conv_d

m00conv/clean:
	$(MAKE) -C m00conv clean

copydebug:
	cp m00conv/m00conv_d test
