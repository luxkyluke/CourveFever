#ifndef TERRAIN_H
#define TERRAIN_H
#include "matrix.h"

class Terrain
{
    Matrix pixels;


public:
    Terrain(int nb_row, int nb_col);
    void print();
};

#endif // TERRAIN_H
