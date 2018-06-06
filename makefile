# -Wall:  Show Compilation Errors AND Warnings
# -std=c++17 Compile for C++ 17 Standard

all : TestMatrix

TestMatrix: main.cpp DenseMatrix.h DenseMatrix.cpp
	g++ -std=c++17 -Wall main.cpp DenseMatrix.cpp -o TestMatrix
