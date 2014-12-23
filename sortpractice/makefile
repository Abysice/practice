CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=sorting.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=testcode

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *~ testcode
