/**
* Prototype for Parallel Matrix Multiplication Algorithm
**/

#include <iostream>
#include <math.h>
#include "DenseMatrix.cpp"


using namespace std;

__global__
void FGEMM(int n, DenseMatrix<float> *a, DenseMatrix<float> *b, DenseMatrix<float> *c) {

    // Will store calculated results from each thread 
    extern __shared__ float calculatedResults[]; 

    if (a->GetRows() == b->GetColumns()) {

    	// Every threadblock gets at least 1 row of matrix A and 1 column of matrix B
    	// There could be an exception to this if matrices are particularly large
		// Each thread gets 1 value from the row and 1 value from the column
		// Then it does the operation on those values

		// Gets value from row of DenseMatrix A 
    	float rowVal =  (*a)(blockIdx.x, threadIdx.x);

    	// Gets value from column of DenseMatrix B
    	float colVal = (*b)(threadIdx.x, blockIdx.x);


    	// Perform thread operation
    	calculatedResults[threadIdx.x] = rowVal * colVal;


    	// Perform reduction on calculated values to add them up.
    	// Resulting value will be assigned to location in DenseMatrix c
    	// This can be made much faster by doing a parallel reduction but this can be added later
    	
    	__syncthreads();

    	if (threadIdx.x == 1) {
	    	for (int i = 1; i < sizeof(calculatedResults)/sizeof(calculatedResults[0]); i++) {
	    			calculatedResults[0] += calculatedResults[i];
	    		}

    		(*c)(blockIdx.x, blockIdx.x) = calculatedResults[0];
     	}
    }

}



int main() {

	int N = 6;
    
    DenseMatrix<float>
        oDM1{{1,2,3},{4,5,6}},
        oDM2{{4,9},{12347,835},{91,7532}};


    cudaMalloc(&oDM1, sizeof(DenseMatrix<float>));
    cudaMalloc(&oDM2, sizeof(DenseMatrix<float>));


    //FGEMM<<<1, 1>>>(N, oDM1, oDM2);


}

