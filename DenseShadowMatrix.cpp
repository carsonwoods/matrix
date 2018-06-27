/*
*   DenseShadowMatrix.cpp
*   Written by Carson Woods
*   2018
*/

#include "DenseMatrix.h"

using namespace std;

template <typename T>
const size_t DenseMatrix<T>::DenseShadowMatrix::Index(const size_t _R, const size_t _C) const { return (_R*Columns)+_C; }

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::~DenseShadowMatrix() {
    delete[] Data;
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix() {
    DenseShadowMatrix(0,0);
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(size_t _R, size_t _C)
    : Rows(_R), Columns(_C), Data(new T[Rows*Columns]) {}


template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(const DenseShadowMatrix& _DSM) { //Copy Constructor
    Rows = _DSM.Rows;
    Columns = _DSM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DSM.Data[x];
    }
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(DenseShadowMatrix&& _DSM) {               //Move Constructor
    //Moves resources to new DenseMatric object
    Rows = _DSM.Rows;
    Columns = _DSM.Columns;
    Data = _DSM.Data;

    //Releases resources of Dense Matrix parameter
    _DSM.Data = nullptr;
    _DSM.Rows = 0;
    _DSM.Columns = 0;

}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(const DenseMatrix<T>& _DM) {          //Copy DenseMatrix Constructor
    Rows = _DM.Rows;
    Columns = _DM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DM.Data[x];
    }
}

template <typename T>
bool DenseMatrix<T>::DenseShadowMatrix::CheckIfEqual(DenseMatrix<T> &_DM) {
    if ((Rows == _DM.Rows) && (Columns == _DM.Columns)) {
        for (size_t x(0); x < Rows*Columns; x++) {
            if (Data[x] != _DM.Data[x]) {
                return false;
            }
        }
        return true;
    } else {
        cout << "false" << endl;
        return false;
    }
}
