/*
*   DenseShadowMatrix.cpp
*   Written by Carson Woods
*   2018
*/

#include "DenseMatrix.h"

using namespace std;

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::~DenseShadowMatrix() {                             //destructor
    delete[] Data;
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix() {                              //default Concstructor
    DenseShadowMatrix(0,0);
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(size_t _R, size_t _C)            //empty constructor
    : Rows(_R), Columns(_C), Data(new T[Rows*Columns]) {}


template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(const DenseShadowMatrix& _DSM) { //copy constructor
    Rows = _DSM.Rows;
    Columns = _DSM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DSM.Data[x];
    }
}

template <typename T>
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(DenseShadowMatrix&& _DSM) {      //move constructor
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
DenseMatrix<T>::DenseShadowMatrix::DenseShadowMatrix(const DenseMatrix<T>& _DM) {     //copy DenseMatrix constructor
    Rows = _DM.Rows;
    Columns = _DM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DM.Data[x];
    }
}

template <typename T>
size_t DenseMatrix<T>::DenseShadowMatrix::Index(const size_t _R, const size_t _C) const { return size_t((_R*Columns)+_C); }


/*
*     ** Overloaded Operators **
*/

template <typename T>
bool DenseMatrix<T>::DenseShadowMatrix::operator==(DenseMatrix<T> &_DM) {
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

template <typename T>
const T &DenseMatrix<T>::DenseShadowMatrix::operator()(size_t _R, size_t _C) const                //overloads () operator for retrieving a
    { return Data[Index(_R,_C)]; }                                                                 //const value at a certain location

template <typename T>
T &DenseMatrix<T>::DenseShadowMatrix::operator()(size_t _R, size_t _C)                //overloads () operator for retrieving a
    { return Data[Index(_R,_C)]; }                                                                 //const value at a certain location
