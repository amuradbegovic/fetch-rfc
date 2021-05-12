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

# the DIR variable specifies what directory will the program be installed to
DIR = /usr/local/bin

fetch-rfc: 
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS) 

clean:
	rm -rf fetch-rfc

install:
	cp fetch-rfc $(DIR)/fetch-rfc
uninstall:
	rm -rf $(DIR)/fetch-rfc
