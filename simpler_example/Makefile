all: simpler_example.o
	g++ -Wall -pedantic -std=c++17 -Iinclude simpler_example.o -o main

%.o: %.cpp
	g++ -Wall -pedantic -std=c++17 -Iinclude -c $< -o $@ 


clean:
	$(RM) *.o main
