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


        //Gets data[index] at (Row,Column) location in Data
        const size_t Index(const size_t _R, const size_t _C) const;

        DenseShadowMatrix();
        DenseShadowMatrix(size_t _R, size_t _C);
        virtual ~DenseShadowMatrix();                                              //Destructor
        DenseShadowMatrix(const DenseShadowMatrix &_DSM);                           //copy constructor
        DenseShadowMatrix(DenseShadowMatrix &&_DSM);                                //move constructor
        DenseShadowMatrix(const DenseMatrix<T> &_DSM);                          //initializer_list constructor
        DenseShadowMatrix &operator=(const DenseShadowMatrix &_RHS);               //overloads copy operator
        DenseShadowMatrix &operator=(DenseShadowMatrix &&_DSM);                     //move operator
};

#endif
