.PHONY: all bin/m00conv debug clean bin/m00conv_debug bin/clean

all: m00conv/m00conv

debug: m00conv/m00conv_debug

clean: m00conv/clean

m00conv/m00conv:
	$(MAKE) -C m00conv m00conv

m00conv/m00conv_debug:
	$(MAKE) -C m00conv m00conv_debug

m00conv/clean:
	$(MAKE) -C m00conv clean
