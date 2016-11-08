#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix
{
    vector<vector<int>> matrix;
    int nbRows, nbCols;

    void initMatrix();
public:
    Matrix(int nbRows, int nbCols);
    Matrix();
    void print();
};

#endif // MATRIX_H
