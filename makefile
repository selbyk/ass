CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
LFLAGS=-pthread
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ass

all: $(SOURCES) $(EXECUTABLE) clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) *.o *~
