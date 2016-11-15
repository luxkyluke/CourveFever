#include "terrain.h"
#include <iostream>

Terrain::Terrain(){

}

Terrain::Terrain(int nb_row, int nb_col){
    pixels = Matrix(nb_row, nb_col);
}

void Terrain::print(){
    pixels.print();
}
