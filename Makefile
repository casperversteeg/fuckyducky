all: main.o
	g++ -Wall -pedantic -std=c++17 -Iinclude main.o -o main

%.o: %.cpp
	g++ -Wall -pedantic -std=c++17 -Iinclude -c $< -o $@ 


clean:
	$(RM) *.o main
