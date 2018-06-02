# -Wall:  Show Compilation Errors AND Warnings
# -std=c++17 Compile for C++ 17 Standard

all : TestMatrix

TestMatrix: tMatrix.cpp main.cpp DenseMatrix.h
	g++ -std=c++17 -Wall  tMatrix.cpp main.cpp -o TestMatrix
