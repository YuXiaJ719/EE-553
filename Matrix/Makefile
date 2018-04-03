main: main.o Matrix.o
	g++ -std=c++11 main.o Matrix.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Matrix.o: Matrix.cpp Matrix.hh
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm *.o main