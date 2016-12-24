OBJECTS = Dijkstra.o main.o
EXEC = main

all: $(EXEC)

run:
	-./main

%.o: %.cpp
	g++ -std=c++14 -Wall -O3 -c -o $@ $^

$(EXEC): $(OBJECTS)
	g++ -std=c++14 -Wall -O3 -o $@ $^

clean:
	-rm *.o $(EXEC)