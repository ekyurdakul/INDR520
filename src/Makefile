OBJECTS = Dijkstra.o main.o
EXECS = main

all: $(EXECS)

%.o: %.cpp
	g++ -std=c++14 -Wall -O3 -c -o $@ $^

$(EXECS): $(OBJECTS)
	g++ -std=c++14 -Wall -O3 -o $@ $^

clean:
	-rm *.o $(EXECS)