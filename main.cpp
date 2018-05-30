#include <iostream> // cout
#include "tMatrix.h"

using namespace std; // cout

int main(int argc, char *argv[]){
   tMatrix
	  oDM1,      // Call Default Constructor at Compile Time
	  oDM2(2,3), // Call Overloaded Constructor (size_t,size_t)
	  oDM3{{1,2,3},{4,5,6}},
	  oDM4{{1,1},{1,1},{1,1}},
		 oDM5(oDM2*oDM3);
		 cout << "oDM1: " << endl << oDM1 << endl
			  << "oDM2: " << endl << oDM2 << endl
			  << "oDM3: " << endl << oDM3 << endl
			  << "oDM4: " << endl << oDM4 << endl
			  << "oDM5: " << endl << oDM5 << endl;
   
		 // oDM2(2,3); // Call Overloaded Constructor (size_t,size_t)
		 ; 
		 //*pDM3;    // Call Default Constructor at Runtime
		 //*pDM4(3,4),   //
		 //*pDM1(&oDM1),
		 //*pDM2(&oDM2);
		 //pDM3 = new tDenseMatrix();
		 return 0;
}
/*
  int* twoDimMatrixMult(vector<vector<int> > m1, vector<vector<int> >  m2) {

  if (m1[0].size() == m2.size()) {
  int product[m1.size()][m1[0].size()];
  int tempProduct = 0;

  for (int i = 0; i < m1.size(); i++) {
  for (int j = 0; j < m1[0].size(); j++) {
  tempProduct = 0;
  for (int k = 0; k < m2.size(); k++) {
  tempProduct += m1[i][k] * m2[k][j];
  }
  product[i][j] = tempProduct;
  }
  }

  for (int x = 0; x < m1.size(); x++) {
  for (int n = 0; n < m2[0].size(); n++) {
  cout << product[x][n] << " ";
  }
  cout << endl;
  }
  } else {
  cout << "Error Dimensional Mismatch. Please modify arrays and retry." << endl;
  }

  return 0;
  }

  int old_main() {

  vector<vector<int> > m1;
  vector<vector<int> > m2;
  vector<int> tempVector;
  int tempValue = 0;

  int m1Rows, m1Cols;
  cout << "Enter row count for first matrix: ";
  cin >> m1Rows;
  cout << "Enter column count for first matrix: ";
  cin >> m1Cols;
  cout << endl;

  //queries user input for matrix 1 values
  for (int m = 0; m < m1Rows; m++) {
  tempVector.clear();
  for (int n = 0; n < m1Cols; n++) {
  cout << "Enter value for first matrix: row " << m+1 << " column " << n+1 << ": ";
  tempValue = 0;
  cin >> tempValue;
  tempVector.push_back(tempValue);
  }
  m1.push_back(tempVector);
  }

  int m2Rows, m2Cols;
  cout << endl << "Enter row count for second matrix: ";
  cin >> m2Rows;
  cout << "Enter column count for second matrix: ";
  cin >> m2Cols;
  cout << endl;

  for (int m = 0; m < m2Rows; m++) {
  tempVector.clear();
  for (int n = 0; n < m2Cols; n++) {
  cout << "Enter value for second matrix: row " << m+1 << " column " << n+1 << ": ";
  tempValue = 0;
  cin >> tempValue;
  tempVector.push_back(tempValue);
  }
  m2.push_back(tempVector);
  }

  twoDimMatrixMult(m1, m2);

  return 0;
  }
//#include <cmath>
//#include <iostream>
//#include <vector>
//using namespace std;

*/
