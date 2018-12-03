/**
* Prototype for Parallel Matrix Multiplication Algorithm
**/

#include <iostream>
#include <math.h>
#include "DenseMatrix.cpp"


using namespace std;

__global__
void FGEMM(int n, DenseMatrix<float> *a, DenseMatrix<float> *b) {

        

}



int main() {
    
    DenseMatrix<float>
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{4,9},{12347,835},{91,7532}},
        oDM3(oDM1*oDM2),
        oDM4(oDM3);


    cout << "Hello World" << endl;

}

