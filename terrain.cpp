#include "terrain.h"
#include <iostream>

Terrain::Terrain(int nb_row, int nb_col){
    pixels = new Matrix(nb_row, nb_col);
}

Terrain::~Terrain(){
    delete pixels;
}

void Terrain::print(){
    pixels->print();
}
