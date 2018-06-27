/*
*   DenseShadowMatrix.cpp
*   Written by Carson Woods
*   2018
*/

#include "DenseMatrix.h"
#include "DenseMatrix.cpp"
#include "DenseShadowMatrix.h"



using namespace std;

template <typename T>
DenseShadowMatrix<T>::~DenseShadowMatrix() {                                   //Destructor
    delete[] Data;
}

template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix() {
    DenseShadowMatrix(0,0);
}

template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix(size_t _R, size_t _C)
    : Rows(_R), Columns(_C), Data(new T[Rows*Columns]) {}




int main(int argc, char *argv[]) {

    DenseMatrix<double> oDM1{{1,2,3},{4,5,6}};

    DenseShadowMatrix<double> denseShadowMatrix1(2,2);


    return 0;
}
