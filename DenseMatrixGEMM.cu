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

	int N = 6;
    
    DenseMatrix<float>
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{4,9},{12347,835},{91,7532}};


    cudaMalloc((void **)&oDM1, sizeof(DenseMatrix<float>));t
    cudaMalloc((void **)&oDM2, sizeof(DenseMatrix<float>));


    FGEMM<<<1, 1>>>(N, oDM1, oDM2)

    cout << "Hello World" << endl;

}

