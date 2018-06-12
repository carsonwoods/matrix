/*
*   DenseMatrix.h
*   Written by Carson Woods and Dan Mailman
*   6/1/2018
*/

#ifndef MATRIX_H
#define MATRIX_H


#include <iostream> //cout

using namespace std; //sets default namespace: standard

class DenseMatrix {

    protected:
        size_t Rows,Columns;
        double *Data;

    public:    

        //Gets data[index] at (Row,Column) location in Data
        const size_t Index(const size_t _R, const size_t _C) const;

        virtual ~DenseMatrix();                                        //Destructor
        DenseMatrix();                                                 //default constructor
        DenseMatrix(size_t _R,size_t _C);                              //default constructor
        DenseMatrix(const DenseMatrix& _DM);                           //copy constructor
        DenseMatrix(DenseMatrix&& _DM);                                //move constructor
        DenseMatrix(initializer_list< initializer_list<double> > _Il); //initializer_list constructor
        DenseMatrix& operator=(const DenseMatrix &_RHS);               //overloads copy operator
        DenseMatrix& operator=(DenseMatrix&& _DM);                     //move operator


        double& operator()(size_t _R, size_t _C)                        //overloads () operator for assigning a
            { return Data[Index(_R,_C)]; }                               //certain value at a certain location

        const double& operator()(size_t _R, size_t _C) const            //overloads () operator for retrieving a
            { return Data[Index(_R,_C)]; }                               //const value at a certain location

        DenseMatrix operator*(const DenseMatrix& RHS) const;            //overloads multiplication operator
        friend ostream& operator<<(ostream& os, const DenseMatrix &DM); //overloads << operator
};


#endif
