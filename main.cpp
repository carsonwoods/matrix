#include <iostream> // cout
#include "DenseMatrix.cpp"
#include "DenseShadowMatrix.cpp"

using namespace std; // cout

int main(int argc, char *argv[]){

    //Driver for tests
    DenseMatrix<double>
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{4,9},{12347,835},{91,7532}},
        oDM3(oDM1*oDM2),
        oDM4(oDM3);


    cout << "oDM1: " << endl << oDM1 << endl
         << "oDM2: " << endl << oDM2 << endl
         << "oDM3: " << endl << oDM3 << endl
         << "oDM4: " << endl << oDM4 << endl;

    DenseMatrix<double>::DenseShadowMatrix test(oDM1);

    oDM2.Update(test);

    cout << "oDM2: " << endl << oDM2 << endl;


    return 0;
}
