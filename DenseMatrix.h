/*
*   DenseMatrix.h
*   Written by Carson Woods and Dan Mailman
*   6/1/2018
*/

#include <iostream> //cout

using namespace std;

class DenseMatrix {
    protected:
        size_t Rows,Columns;
        double *Data;

    public:
        //default AND initializer constructor
        DenseMatrix(size_t _R=0,size_t _C=0) :
            Rows(_R), Columns(_C), Data(new double[Rows*Columns]) {}

        //copy constructor
        DenseMatrix(const DenseMatrix& _DM) {
            cout << "Why is this happening" << endl;
            this->Rows = _DM.Rows;
            this->Columns = _DM.Columns;
            this->Data = _DM.Data;
        }

        //move constructor
        DenseMatrix(DenseMatrix&& _DM) {
            //Moves resources to new DenseMatric object
            this->Rows = _DM.Rows;
            this->Columns = _DM.Columns;
            this->Data = _DM.Data;

            //Releases resources of Dense Matrix parameter
            _DM.Data = nullptr;
            _DM.Rows = 0;
            _DM.Columns = 0;

        }

        //initializer_list constructor
        DenseMatrix(initializer_list< initializer_list<double> > _Il) {
            //sets size of matrix based on size of _Il
            Rows = _Il.size();
            Columns= _Il.begin()->size();
            Data = new double[Rows*Columns];

            //define indices for data
            size_t R(0), C(0);

            //iterates through __Il and adds its data to proper location in Data
            for (auto iRow(_Il.begin()); iRow != _Il.end(); ++iRow) {
                for (auto iElement(iRow->begin()); iElement != iRow->end(); ++iElement) {
                    (*this)(R,C) = *iElement;
                    C++;
                }
                R++;
                C = 0;
            }
        }


        //clears data when object leaves scope
        virtual ~DenseMatrix() {
            delete[] Data;
            cout << "~DenseMatrix(): Return" << endl;
        }


        //Gets data[index] at (Row,Column) location in Data
        const size_t Index(const size_t _R, const size_t _C) const { return (_R*Columns)+_C; }

        /*
        *     ** Overloaded Operators **
        */

        //overloads assignment operator
        DenseMatrix& operator=(const DenseMatrix &_RHS) {
            //checks for self assignment
            if (&_RHS == this) {
                return *this;
            }

            //checks for dimensinal mismatch
            if (!((this->Rows == _RHS.Rows && this->Columns == _RHS.Columns))) {
                //if it occures Data is cleared then resized.
                delete[] Data;
                this->Rows = _RHS.Rows;
                this->Columns = _RHS.Columns;
                Data = new double[Rows*Columns];

            }

            //populates this->Data with data from parameter
            for (size_t iElement(0); iElement < (Rows*Columns); iElement++) {
                Data[iElement] = _RHS.Data[iElement];
            }

            return *this;
        }

        //overloads () operator for assigning a certain value at a certain location
        double& operator()(size_t _R, size_t _C) {
            return Data[Index(_R,_C)];
        }

        //overloads () operator for retrieving a const value at a certain location
        const double& operator()(size_t _R, size_t _C) const {
            return Data[Index(_R,_C)];
        }

        DenseMatrix& operator=(DenseMatrix&& _DM) {
            if (this != &_DM) {
                delete[] Data;

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

        //overloads multiplication operator
        DenseMatrix operator*(const DenseMatrix& RHS) const  {
            const DenseMatrix &LHS(*this);


            printf("DenseMatrix::operator*(): Enter.\n");

            //test for dimensional mismatch
            if (((LHS.Columns != RHS.Rows))) {
                printf("Error: Columns of LHS and Rows of RHS must Match.\n");
                printf("Current Columns: %ld\n",LHS.Columns);
                printf("Current Rows: %ld\n",RHS.Rows);
                return DenseMatrix();
        	}

        	DenseMatrix RET(LHS.Rows,RHS.Columns);

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

        friend ostream& operator<<(ostream& os, const DenseMatrix &DM) {
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
                    os << " ]" << " }";
                }
            }
            return os;
        }

};
