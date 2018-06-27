# -Wall:  Show Compilation Errors AND Warnings
# -std=c++17 Compile for C++ 17 Standard

all : TestMatrix 

TestMatrix: main.cpp DenseMatrix.h DenseMatrix.cpp DenseShadowMatrix.h DenseShadowMatrix.cpp
	g++ -std=c++17 -Wall main.cpp DenseMatrix.cpp DenseShadowMatrix.cpp -o TestMatrix
