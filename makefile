output: main.o DenseMatrix.o
	g++ main.o DenseMatrix.o -o output

main.o: main.cpp
	g++ -c main.cpp

clean:
	-rm *.o output
