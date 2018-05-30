#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class DenseMatrix {

    int rows;
    int columns;
    vector<vector<int> > denseMatrix;

public:

    //default constructor creates an empty 0x0 array
    DenseMatrix() {
        rows = 0;
        columns = 0;
        intializeMatrix();
    }

    //allows for matrix instantiation of a certain size
    DenseMatrix(int r, int c) {
        rows = r;
        columns = c;
        intializeMatrix();
    }

    void setRows(int rowAmt) {
        rows = rowAmt;
        intializeMatrix();
    }

    void setColumns(int colAmt) {
        columns = colAmt;
        intializeMatrix();
    }

    int getRows() const{
        return rows;
    }

    int getColumns() const {
        return columns;
    }

    vector<vector<int> > getMatrix() {
        return denseMatrix;
    }

    void setMatrixValue(int r, int c, int value) {
        denseMatrix[r][c] = value;
    }

    void intializeMatrix() {

        denseMatrix.clear();

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                    denseMatrix[x].push_back(0);
            }
        }
    }



};
