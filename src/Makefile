CFLAGS = -std=c++14 -O3 -Wall
OBJECTS = Dijkstra.o main.o
EXEC = main

all: $(EXEC)

debug: CFLAGS += -g -DDEBUG
debug: all

run:
	-./$(EXEC)

%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $^

$(EXEC): $(OBJECTS)
	g++ $(CFLAGS) -o $@ $^

clean:
	-rm *.o $(EXEC)

.PHONY: clean run debug all