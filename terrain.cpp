#include "terrain.h"
#include <iostream>

int Terrain::getWidth() const
{
    return width;
}

int Terrain::getHeight() const
{
    return height;
}

QImage Terrain::getPixels() const
{
    return pixels;
}

void Terrain::update(QGLWidget* renderer){
    pixels =  renderer->grab().toImage();
}

Terrain::Terrain(){
    width = 0;
    height =0;
}

Terrain::Terrain(int nb_row, int nb_col){
    //pixels = Matrix(nb_row, nb_col);
    width = nb_row;
    height = nb_col;
}


