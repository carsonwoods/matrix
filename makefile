# -Wall:  Show Compilation Errors AND Warnings
# -std=c++17 Compile for C++ 17 Standard

all : TestMatrix TestShadowMatrix

TestMatrix: main.cpp DenseMatrix.h DenseMatrix.cpp
	g++ -std=c++17 -Wall main.cpp DenseMatrix.cpp -o TestMatrix

TestShadowMatrix: DenseShadowMatrix.cpp DenseShadowMatrix.h DenseMatrix.h DenseMatrix.cpp
	g++ -std=c++17 -Wall DenseMatrix.cpp DenseShadowMatrix.cpp -o TestShadowMatrix
