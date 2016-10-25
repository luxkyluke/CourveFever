#include "matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int nbRows, int nbCols){
    this->nbRows=nbRows;
    this->nbCols=nbCols;
    initMatrix();
}

void Matrix::print(){
    for (int i = 0; i < nbRows; ++i) {
        for (int j = 0; j < nbCols; ++j) {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

void Matrix::initMatrix(){
    matrix.resize(nbRows);
    for (int i = 0; i < nbRows; ++i) {
        matrix[i].resize(nbCols);
        for (int j = 0; j < nbCols; ++j) {
            matrix[i][j] = 0;
        }
    }
}
