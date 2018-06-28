/*
*   DenseMatrix.cpp
*   Written by Carson Woods and Dan Mailman
*   2018
*/

#include "DenseMatrix.h"

using namespace std;

template <typename T>
DenseMatrix<T>::~DenseMatrix() {                                   //Destructor
    delete[] Data;
}

template <typename T>
DenseMatrix<T>::DenseMatrix() {                                    //Default Constructor
    DenseMatrix(0,0);
}

template <typename T>
DenseMatrix<T>::DenseMatrix(size_t _R,size_t _C) :                 //Initializer constructor
    Rows(_R), Columns(_C), Data(new T[Rows*Columns]) {}

template <typename T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix& _DM) {          //Copy Constructor
    Rows = _DM.Rows;
    Columns = _DM.Columns;
    Data = new T[Rows*Columns];
    for (size_t x(0); x < Rows*Columns; x++) {
        Data[x] = _DM.Data[x];
    }
}

template <typename T>
DenseMatrix<T>::DenseMatrix(DenseMatrix&& _DM) {               //Move Constructor
    //Moves resources to new DenseMatric object
    this->Rows = _DM.Rows;
    this->Columns = _DM.Columns;
    this->Data = _DM.Data;

    //Releases resources of Dense Matrix parameter
    _DM.Data = nullptr;
    _DM.Rows = 0;
    _DM.Columns = 0;

}


template <typename T>
DenseMatrix<T>::DenseMatrix(initializer_list< initializer_list< T > > _Il) { //Initializer List Constructor
    //Sets size of matrix based on size of _Il
    Rows = _Il.size(); //Gets row size from external iterator list size
    Columns= _Il.begin()->size(); //Gets column size from internal iterator list size
    Data = new T[Rows*Columns];

    //Define indices for data
    size_t R(0), C(0);

    //Iterates through __Il and adds its data to proper location in Data
    for (auto iRow(_Il.begin()); iRow != _Il.end(); ++iRow) {
        for (auto iElement(iRow->begin()); iElement != iRow->end(); ++iElement) {
            (*this)(R,C) = *iElement;
            C++;
        }
        R++;
        C = 0;
    }
}


//Gets data[index] at (Row,Column) location in Data
template <typename T>
const size_t DenseMatrix<T>::Index(const size_t _R, const size_t _C) const { return (_R*Columns)+_C; }


/*
*     ** Overloaded Operators **
*/

//Overloads multiplication operator
template <typename T>
DenseMatrix<T> DenseMatrix<T>::operator*(const DenseMatrix& RHS) const  {
    const DenseMatrix<T> &LHS(*this);

    //Test for dimensional mismatch
    if (((LHS.Columns != RHS.Rows))) {
        printf("Error: Columns of LHS and Rows of RHS must Match.\n");
        printf("Current Columns: %ld\n",LHS.Columns);
        printf("Current Rows: %ld\n",RHS.Rows);
        return DenseMatrix();
    }


    DenseMatrix<T> RET(LHS.Rows,RHS.Columns);

    double Sum = 0;

    for (size_t iRow(0); iRow < LHS.Rows; iRow++) {
        for (size_t iCol(0); iCol < RHS.Columns; iCol++) {
            Sum = 0;
            for (size_t iSum(0); iSum < RHS.Rows; iSum++) {
                Sum += LHS(iRow, iSum) * RHS(iSum,iCol);
            }
            RET(iRow, iCol) = Sum;
        }
    }
    return RET;
}

//Overloads assignment operator for copy
template <typename T>
DenseMatrix<T> & DenseMatrix<T>::operator=(const DenseMatrix &_RHS) {
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
DenseMatrix<T> & DenseMatrix<T>::operator=(DenseMatrix &&_DM) {
    if (this != &_DM) {
        delete[] Data; //Ensures Data is clear before proceeding

        Data = _DM.Data;
        Rows = _DM.Rows;
        Columns = _DM.Columns;

        //Releases resources of Dense Matrix parameter
        _DM.Data = nullptr;
        _DM.Rows = 0;
        _DM.Columns = 0;
    }
    return *this;
}



//Overloads copy operator to update data from DenseShadowMatrix
template <typename T>
DenseMatrix<T>& DenseMatrix<T>::operator=(const DenseMatrix<T>::DenseShadowMatrix &_RHS) {

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

//Overloads move operator to move DenseShadowMatrix into DenseMatrix
template <typename T>
DenseMatrix<T>& DenseMatrix<T>::operator=(DenseMatrix<T>::DenseShadowMatrix &&_DSM) {
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

template <typename T>
bool DenseMatrix<T>::operator==(DenseMatrix<T>::DenseShadowMatrix &_DSM) {
    if ((Rows == _DSM.Rows) && (Columns == _DSM.Columns)) {
        for (size_t x(0); x < Rows*Columns; x++) {
            if (Data[x] != _DSM.Data[x]) {
                return false;
            }
        }
        return true;
    } else {
        cout << "false" << endl;
        return false;
    }
}
