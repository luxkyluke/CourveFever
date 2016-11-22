#include "terrain.h"
#include <iostream>
#include <QPoint>

int Terrain::getWidth() const{
    return width;
}

int Terrain::getHeight() const
{
    return height;
}

QImage& Terrain::getPixels() {
    return pixels;
}

QColor Terrain::getPixel(int x, int y){
    return pixels.pixel(x, y);
}

QColor Terrain::getPixel(QPointF& pt){
    return pixels.pixel(pt.toPoint());
}

void Terrain::update(QGLWidget* renderer){
    pixels =  renderer->grab().toImage();
}

void Terrain::changeCoordInImgDim(const float x, const float y,
                               int *_x, int *_y){
    *_x = getXImgCoord(x);
    *_y = getYImgCoord(y);
}

QPoint Terrain::getCoordInImgDim(QPointF &pt){
    return QPoint(getXImgCoord(pt.x()), getYImgCoord(pt.y()));
}

int Terrain::getXImgCoord(const float x){
    return x +(width/2);
}

int Terrain::getYImgCoord(const float y){
     return -y + (height/2);
}

Terrain::Terrain(){
    width = 0;
    height = 0;
}

Terrain::Terrain(int nb_row, int nb_col){
    width = nb_row;
    height = nb_col;
}


