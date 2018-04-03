main: main.o add.o operatorsubscrip.o operatorMulti.o print.o
	g++ -std=c++11 main.o add.o operatorsubscrip.o operatorMulti.o print.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

add.o: add.hh Matrix.hh
	g++ -std=c++11 -c add.hh

operatorsubscrip.o: operatorsubscrip.hh Matrix.hh
	g++ -std=c++11 -c operatorsubscrip.hh

operatorMulti.o: operatorMulti.hh Matrix.hh
	g++ -std=c++11 -c operatorMulti.hh

print.o: print.hh Matrix.hh
	g++ -std=c++11 -c print.hh

clean:
	rm *.o main.exe