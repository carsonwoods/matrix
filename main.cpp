#include <iostream> // cout
#include "DenseMatrix.h"

using namespace std; // cout

int main(int argc, char *argv[]){

    /**
    DenseMatrix
        oDM1,      // Call Default Constructor at Compile Time
        oDM2(2,3), // Call Overloaded Constructor (size_t,size_t)
        oDM3{{1,2,3},{4,5,6}},
        oDM4{{1,1},{1,1},{1,1}},
        oDM5(oDM3*oDM4);
    cout << "oDM1: " << endl << oDM1 << endl
         << "oDM2: " << endl << oDM2 << endl
         << "oDM3: " << endl << oDM3 << endl
         << "oDM4: " << endl << oDM4 << endl
         << "oDM5: " << endl << oDM5 << endl
         << "oDM5[2][2]: " << endl << oDM5(1,1) << endl;
    **/


    DenseMatrix
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{1,1},{1,1},{1,1}},
        oDM3(oDM1*oDM2);

    //cout << "oDM3: " << endl << oDM3 << endl;


    cout << "oDM1: " << endl << oDM1 << endl
         << "oDM2: " << endl << oDM2 << endl
         << "oDM3: " << endl << oDM3 << endl;



    /* OLD DRIVER CODE FOR DEPRECATED tMatrix Class */
    /*
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
         << "oDM5: " << endl << oDM5 << endl
         << "oDM5[2][2]: " << endl << oDM5[1][1] << endl;

    */


    return 0;
}
