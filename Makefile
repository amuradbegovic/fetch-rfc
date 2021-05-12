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

fetch-rfc: 
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS) 

clean:
	rm -rf fetch-rfc
