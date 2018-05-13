run:		readset.o grid.o calculator.o main.o
		g++ -o run readset.o grid.o calculator.o main.o
readset.o:	readset.cpp
		g++ -O3 -c readset.cpp
grid.o:		grid.cpp
		g++ -O3 -c grid.cpp
calculator.o:	calculator.cpp
		g++ -O3 -c calculator.cpp
main.o:		main.cpp
		g++ -c main.cpp
clean:
		rm *.o
