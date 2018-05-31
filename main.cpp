#include <iostream> // cout
#include "tMatrix.h"

using namespace std; // cout

int main(int argc, char *argv[]){
    tMatrix
	    oDM1,      // Call Default Constructor at Compile Time
	    oDM2(2,3), // Call Overloaded Constructor (size_t,size_t)
	    oDM3{{1,2,3},{4,5,6}},
	    oDM4{{1,1},{1,1},{1,1}},
		oDM5(oDM3*oDM4);
	cout << "oDM1: " << endl << oDM1 << endl
	     << "oDM2: " << endl << oDM2 << endl
	     << "oDM3: " << endl << oDM3 << endl
		 << "oDM4: " << endl << oDM4 << endl
		 << "oDM5: " << endl << oDM5 << endl;

		 //*pDM3;    // Call Default Constructor at Runtime
		 //*pDM4(3,4),   //
		 //*pDM1(&oDM1),
		 //*pDM2(&oDM2);
		 //pDM3 = new tDenseMatrix();

    return 0;
}
