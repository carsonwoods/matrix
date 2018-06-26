/*
*   DenseCudaMatrix.h
*   Written by Carson Woods
*   2018
*/

#ifndef DENSESHADOWMATRIX_H
#define DENSESHADOWMATRIX_H

#include <iostream> //cout

using namespace std;

template <typename T>
class DenseShadowMatrix {

    protected:
        size_t Rows,Columns;
        T *Data;

    public:
        DenseShadowMatrix();
        DenseShadowMatrix(size_t _R, size_t _C);


};

#endif
