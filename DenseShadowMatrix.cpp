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
const size_t DenseShadowMatrix<T>::Index(const size_t _R, const size_t _C) const { return (_R*Columns)+_C; }

template <typename T>
DenseShadowMatrix<T>::~DenseShadowMatrix() {
    delete[] Data;
}

template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix() {
    DenseShadowMatrix(0,0);
}

template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix(size_t _R, size_t _C)
    : Rows(_R), Columns(_C), Data(new T[Rows*Columns]) {}


template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix(const DenseShadowMatrix& _DSM) {          //Copy Constructor
    Rows = _DSM.Rows;
    Columns = _DSM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DSM.Data[x];
    }
}

template <typename T>
DenseShadowMatrix<T>::DenseShadowMatrix(DenseShadowMatrix&& _DSM) {               //Move Constructor
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
DenseShadowMatrix<T>::DenseShadowMatrix(const DenseMatrix<T>& _DM) {          //Copy DenseMatrix Constructor
    Rows = _DM.Rows;
    Columns = _DM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DM.Data[x];
    }
}

/*
*     ** Overloaded Operators **
*/

//Overloads assignment operator for copy
template <typename T>
DenseShadowMatrix<T> & DenseShadowMatrix<T>::operator=(const DenseShadowMatrix &_RHS) {
    //Checks for self assignment
    if (&_RHS == this) {
        return *this;
    }

    //Checks for dimensinal mismatch
    if (!((this->Rows == _RHS.Rows && this->Columns == _RHS.Columns))) {
        //If it occures Data is cleared then resized.
        delete[] Data;
        this->Rows = _RHS.Rows;
        this->Columns = _RHS.Columns;
        Data = new T[Rows*Columns];
    }

    //Populates this->Data with data from parameter
    for (size_t iElement(0); iElement < (Rows*Columns); iElement++) {
        Data[iElement] = _RHS.Data[iElement];
    }
    return *this;
}

//Overloads assignment operator for move
template <typename T>
DenseShadowMatrix<T> & DenseShadowMatrix<T>::operator=(DenseShadowMatrix &&_DSM) {
    if (this != &_DSM) {
        delete[] Data; //Ensures Data is clear before proceeding

        Data = _DSM.Data;
        Rows = _DSM.Rows;
        Columns = _DSM.Columns;

        //Releases resources of Dense Matrix parameter
        _DSM.Data = nullptr;
        _DSM.Rows = 0;
        _DSM.Columns = 0;
    }
    return *this;
}

int main(int argc, char *argv[]) {

    //Driver for tests
    DenseMatrix<double>
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{4,9},{12347,835},{91,7532}},
        oDM3(oDM1*oDM2),
        oDM4(oDM3);


    cout << "oDM1: " << endl << oDM1 << endl
         << "oDM2: " << endl << oDM2 << endl
         << "oDM3: " << endl << oDM3 << endl
         << "oDM4: " << endl << oDM4 << endl;


    DenseShadowMatrix<double> denseShadowMatrix1(oDM1);

    cout << "denseShadowMatrix1: " << endl << denseShadowMatrix1 << endl;

    return 0;
}
