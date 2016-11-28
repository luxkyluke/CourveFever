#include "terrain.h"
#include "game.h"
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

void Terrain::paintEvent(QPaintEvent *pe){
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(Qt::NoPen);

    painter.translate(width/2, height/2);
    painter.scale(1, -1);
    game->draw(&painter);
    painter.end();
}

//void Terrain::update(QGLWidget* renderer){
//    pixels =  renderer->grab().toImage();
//}

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

QPixmap Terrain::getPic() const
{
    return pic;
}

Terrain::Terrain (QWidget *parent): QWidget(parent){
    width = 0;
    height = 0;
}

Terrain::Terrain(const Game* g, int w,
                 int h, QWidget *parent):
            QWidget(parent), game(g){
    width = w;
    height = h;
    pic = QPixmap(width, height);
}


