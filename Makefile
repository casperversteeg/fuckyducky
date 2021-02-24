all: main.o
	g++ -Wall -pedantic -std=c++17 -Iinclude -Ilib/gtest main.o -o main -lgtest -lpthread

%.o: %.cpp
	g++ -Wall -pedantic -std=c++17 -Iinclude -Ilib/gtest -c $< -o $@ -lgtest -lpthread


clean:
	$(RM) *.o main
