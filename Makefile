# the compiler and the linker
CC = cc

# libraries
LIBS = `curl-config --libs` 

# compiler and linker flags 
CFLAGS = -std=c99 -pedantic -Wall -O2

# linker flags
LDFLAGS = $(LIBS)

# source files:
SRC = fetch-rfc.c

# the PREFIX variable specifies what directory will the program be installed to
PREFIX = /usr/local/

fetch-rfc: 
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS) 

clean:
	rm -rf fetch-rfc

install:
	cp fetch-rfc $(PREFIX)/bin/fetch-rfc
	mkdir -p $(PREFIX)/share/man/man1
	cp fetch-rfc.1 $(PREFIX)/share/man/man1/fetch-rfc.1
uninstall:
	rm -rf $(PREFIX)/bin/fetch-rfc
	rm -rf $(PREFIX)/share/man/man1/fetch-rfc.1
