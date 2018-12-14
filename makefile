# -Wall:  Show Compilation Errors AND Warnings
# -std=c++17 Compile for C++ 17 Standard

all : TestMatrix

TestMatrix: main.cpp DenseMatrix.h DenseMatrix.cpp DenseShadowMatrix.cpp
	g++ -std=c++17 -Wall main.cpp -o TestMatrix

TestCuda: DenseMatrixGEMM.cu DenseMatrix.h DenseMatrix.cpp
	nvcc -std=c++11 DenseMatrixGEMM.cu DenseMatrix.cpp -o DenseMatrixTest

clean:
	rm TestMatrix DenseMatrix
