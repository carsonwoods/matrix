/*
*   DenseMatrix.h
*   Written by Carson Woods and Dan Mailman
*   2018
*/

#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <iostream>

using namespace std;

template <typename T>
class DenseMatrix {

public:
    class DenseShadowMatrix {
    private:
        size_t Rows,Columns;
        T *Data;
    public:

        DenseShadowMatrix();
        DenseShadowMatrix(size_t _R, size_t _C);
        DenseShadowMatrix(const DenseShadowMatrix &_DSM);  //copy constructor
        DenseShadowMatrix(DenseShadowMatrix &&_DSM);       //move constructor
        DenseShadowMatrix(const DenseMatrix<T> &_DM);      //copy DenseMatrix constructor
        virtual ~DenseShadowMatrix();                      //Destructor

        // Gets data[index] at (Row,Column) location in Data
        size_t Index(const size_t _R, const size_t _C) const;

        bool operator==(DenseMatrix &_DM);                 //opeartor for comparing DenseMatrix and DenseShadowMatrix
        T &operator()(size_t _R, size_t _C);               //overloads () operator for assigning a certain value at a certain location
        const T &operator()(size_t _R, size_t _C) const;   //overloads () operator for retrieving a const value at a certain location


        DenseShadowMatrix &operator=(const DenseShadowMatrix &_RHS) {  //overloads copy operator
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


        DenseShadowMatrix &operator=(DenseShadowMatrix &&_DSM){                 //move operator
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
        };


        friend ostream& operator<<(ostream& os, const DenseShadowMatrix &DSM) {
            os << "{";
            for (size_t R(0); R < DSM.Rows; R++) {
                os << " [";
                for (size_t C(0); C < DSM.Columns; C++) {
                    os << " " << DSM(R,C);
                }
                if (R != DSM.Rows-1) {
                    os << " ]" << endl << " ";
                } else {
                    os << " ]";
                }
            }
            os << " }";
            return os;
        }

        size_t GetRows();
        size_t GetColumns();

        //declare friend class(es)
        friend class DenseMatrix;

    };


//DenseMatrix Class
private:
    size_t Rows,Columns;
    T *Data;

public:

    DenseMatrix();                                                 //default constructor
    DenseMatrix(size_t _R,size_t _C);                              //default constructor
    DenseMatrix(const DenseMatrix &_DM);                           //copy constructor
    DenseMatrix(DenseMatrix &&_DM);                                //move constructor
    DenseMatrix(initializer_list< initializer_list<T> > _Il);      //initializer_list constructor
    virtual ~DenseMatrix();                                        //Destructor

    //Gets data[index] at (Row,Column) location in Data
    size_t Index(const size_t _R, const size_t _C) const;

    DenseMatrix &operator=(const DenseMatrix &_RHS);               //overloads copy operator
    DenseMatrix &operator=(DenseMatrix &&_DM);                     //move operator

    //these will be used to update DenseMatrix to current shadow
    DenseMatrix &operator=(const DenseShadowMatrix &_DSM);         //copy operator
    DenseMatrix &operator=(DenseShadowMatrix &&_DSM);              //move operator

    bool operator==(DenseShadowMatrix &_DSM);                      //compares equality of DenseMatrix and DenseShadowMatrix
    T &operator()(size_t _R, size_t _C);                           //overloads () operator for assigning a certain value at a certain location
    const T &operator()(size_t _R, size_t _C) const;               //overloads () operator for retrieving a const value at a certain location
    DenseMatrix operator*(const DenseMatrix & RHS) const;          //overloads multiplication operator

    friend ostream& operator<<(ostream& os, const DenseMatrix<T> &DM) {
        os << "{";
        for (size_t R(0); R < DM.Rows; R++) {
            os << " ";
            os << "[";
            for (size_t C(0); C < DM.Columns; C++) {
                os << " " << DM(R,C);
            }
            if (R != DM.Rows-1) {
                os << " ]" << endl << " ";
            } else {
                os << " ]";
            }
        }
        os << " }";
        return os;
    }

    size_t GetRows();
    size_t GetColumns();

    //declare friend class(es)
    friend class DenseShadowMatrix;

};

#endif
