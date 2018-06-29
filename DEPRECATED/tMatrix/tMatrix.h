#include <cstdio>    // size_t
#include <vector>    // vector

using namespace std; // vector

struct tRC {size_t NumRows,NumCols;} ;

typedef vector<int> tRow;

struct tMatrix {
   vector< tRow > Data;

   void Zero(size_t pNumRows,size_t pNumCols);
   const tRC size() const; // TODO: WHY??
   tMatrix();                                // Default Constructor
   tMatrix(size_t pNumRows, size_t pNumCols);
   tMatrix(initializer_list<tRow> il);

   tMatrix operator*(const tMatrix& RHS) const;
   tRow    operator[](int iElt);
};

ostream& operator<<(ostream& os, const    tRow& V);
ostream& operator<<(ostream& os, const tMatrix& M);
