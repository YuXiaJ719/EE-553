main: main.o Matrix.o
	g++ main.o Matrix.o -o main

main.o: main.cpp
	g++ -c main.cpp

Matrix.o: Matrix.cpp Matrix.hh
	g++ -c Matrix.cpp

clean:
	rm *.o main.exe