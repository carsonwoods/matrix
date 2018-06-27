/*
*   DenseShadowMatrix.h
*   Written by Carson Woods
*   2018
*/

#ifndef DENSESHADOWMATRIX_H
#define DENSESHADOWMATRIX_H

#include <iostream> //cout

using namespace std;

template <typename T>
class DenseShadowMatrix {

    public:
        size_t Rows,Columns;
        T *Data;

        //Gets data[index] at (Row,Column) location in Data
        const size_t Index(const size_t _R, const size_t _C) const;

        DenseShadowMatrix();
        DenseShadowMatrix(size_t _R, size_t _C);
        virtual ~DenseShadowMatrix();                                              //Destructor
        DenseShadowMatrix(const DenseShadowMatrix &_DSM);                          //copy constructor
        DenseShadowMatrix(DenseShadowMatrix &&_DSM);                               //move constructor
        DenseShadowMatrix(const DenseMatrix<T> &_DM);                             //copy DenseMatrix constructor
        DenseShadowMatrix &operator=(const DenseShadowMatrix &_RHS);               //overloads copy operator
        DenseShadowMatrix &operator=(DenseShadowMatrix &&_DSM);                    //move operator

        bool CheckIfEqual(DenseMatrix<T> &_DM);

        T &operator()(size_t _R, size_t _C)                            //overloads () operator for assigning a
            { return Data[Index(_R,_C)]; }                             //certain value at a certain location

        const T &operator()(size_t _R, size_t _C) const                //overloads () operator for retrieving a
            { return Data[Index(_R,_C)]; }                             //const value at a certain location

        friend ostream& operator<<(ostream& os, const DenseShadowMatrix<T> &DSM) {
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
};

#endif
