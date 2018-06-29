#include <iostream> // cout
#include "tMatrix.h"

#define DEBUG

//overloads operator for << of tRow (typedef for vector<int>)
ostream& operator<<(ostream& os, const tRow& V){
    os << "[";
    for (size_t iElt(0); iElt < V.size(); ++iElt) {
	    os << V[iElt];
	    if (iElt != V.size() - 1)
		   os << ", ";
     }
     os << "]";
     return os;
}

//overloads operator for << of tMatrix
ostream& operator<<(ostream& os, const tMatrix& M){
    os << "{";
    for (size_t iRow(0); iRow < M.Data.size(); ++iRow) {
	    os << " ";
	    os << M.Data[iRow];
	    if (iRow != M.Data.size() - 1)
		   os << "\n ";
     }
     os << " }";
     return os;
}

const tRC tMatrix::size() const {
    return {Data.size(),Data[0].size()};
}

void tMatrix::Zero(size_t pNumRows,size_t pNumCols){
    #ifdef xDEBUG
        printf("Zero(%ld,%ld): ENTER.\n",pNumRows,pNumCols);
    #endif

    Data.clear();
    tRow rRow(pNumCols,0) ;
    for (size_t iRow(0); iRow < pNumRows; iRow++) {
	    Data.push_back(rRow);

    }
    #ifdef xDEBUG
        printf("Zero(): Data.size(%ld).\n",Data.size());
        printf("Zero(%ld,%ld): RETURN.\n",pNumRows,pNumCols);
    #endif
}


tMatrix::tMatrix(){
    cout << "tMatrix(default): RETURN.\n";
}


tMatrix::tMatrix(size_t pNumRows, size_t pNumCols) {
    #ifdef DEBUG
        printf("tMatrix(%ld,%ld): ENTER.\n",pNumRows,pNumCols);
    #endif

        Zero(pNumRows,pNumCols); // Make a NumRows X NumCols Zero Matrix

    #ifdef xDEBUG
        printf("tMatrix(%ld,%ld): RETURN.\n",pNumRows,pNumCols);
    #endif
}


tMatrix::tMatrix(initializer_list<tRow> il)
    : Data(il) {

    #ifdef DEBUG
    printf ("tMatrix(IL): ENTER.\n");
    #endif

    // TODO: Implement for Learning Purposes

    #ifdef DEBUG
    printf ("tMatrix(IL): RETURN.\n");
    #endif
}


tMatrix tMatrix::operator*(const tMatrix& RHS) const  {
    const tMatrix LHS(*this);

    printf("tMatrix::operator*(): Enter.\n");

    //test for dimensional mismatch
    if (((LHS.size()).NumCols) != ((RHS.size()).NumRows)){
        printf("Error: Columns of LHS and Rows of RHS must Match.\n");
        printf("Current Columns: %ld\n",LHS.size().NumCols);
        printf("Current Rows: %ld\n",RHS.size().NumRows);
        return tMatrix();
	}

	tMatrix RET(LHS.size().NumRows,RHS.size().NumCols);
    // TODO: printf
    printf("tMatrix of dim: %ldx%ld",RET.size().NumRows,RET.size().NumCols);
	int Sum = 0;

	for (size_t iRow(0); iRow < LHS.size().NumRows; iRow++) {
	    for (size_t iCol(0); iCol < LHS.size().NumRows; iCol++) {
		    Sum = 0;
		    for (size_t iSum(0); iSum < RHS.size().NumRows; iSum++) {
			    Sum += LHS.Data[iRow][iSum] * RHS.Data[iSum][iCol];
			}
		    RET.Data[iRow][iCol] = Sum;
		}
	}
	return RET;
}


tRow tMatrix::operator[](int iElt) {
    return Data[iElt];
}
