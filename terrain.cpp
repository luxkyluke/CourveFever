#include "terrain.h"
#include "game.h"
#include <iostream>


static const QColor BLACK_COLOR(0, 0, 0, 255);
static const QColor WHITE_COLOR(255, 255, 255, 255);

int Terrain::getWidth() const{
    return width;
}

int Terrain::getHeight() const{
    return height;
}

//QImage& Terrain::getPixels() {
//    return pixels;
//}

//QColor Terrain::getPixel(int x, int y){
//    return pixels.pixel(x, y);
//}

//QColor Terrain::getPixel(QPointF& pt){
//    return pixels.pixel(pt.toPoint());
//}

void Terrain::drawBorders(QPainter& painter){
    QPen pen(WHITE_COLOR); //Qt::white
    pen.setWidth(5);

    painter.setPen(pen);
    painter.drawLine(QPoint(0, 0), QPoint(width, 0));
    painter.drawLine(QPoint(0, 0), QPoint(0, height));
    painter.drawLine(QPoint(0, height), QPoint(width, height));
    painter.drawLine(QPoint(width, 0), QPoint(width, height));
}


void Terrain::paintEvent(QPaintEvent *pe){
    QPainter painter;
    painter.begin(&pic);

    //draw borders
    if(isNoBorder){
        drawBorders(painter);
        isNoBorder = false;
    }

    //draw game
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

QPointF Terrain::getCoordInLandmarkDim(QPoint &pt, const int &w, const int &h){
    return QPointF(getXLandmarkCoord(pt.x(), w), getYLandmarkCoord(pt.y(), h));
}

int Terrain::getXImgCoord(const float x){
    return x +(width/2);
}

float Terrain::getXLandmarkCoord(const int x, const int w){
    return x -(w/2);
}

int Terrain::getYImgCoord(const float y){
     return -y + (height/2);
}

float Terrain::getYLandmarkCoord(const int y, const int h){
    return -y + (h/2);
}

QPixmap Terrain::getPic() const{
    return pic;
}

bool Terrain::isBlack(QPointF pt, QColor *c){
    QImage pixels = pic.toImage();
    QPoint coordsInIMG = getCoordInImgDim(pt);
    *c = pixels.pixelColor(coordsInIMG);
    return(*c == BLACK_COLOR);
}

bool Terrain::isInCollision(Player* p, QColor* c){
    QVector<QPointF> pts = p->getCollisionPoints();
    foreach(QPointF pt, pts){
        if(!isBlack(pt, c)){
            return true;
        }
    }
    return false;
}

bool Terrain::isBordersColor(QColor c){
    return c==WHITE_COLOR;
}


//bool Terrain::isWall(QPointF pt) {
//    float maxX = this->width/2;
//    float maxY = this->height/2;

//    if(pt.x()>maxX || pt.x() < -maxX/2
//            || pt.y()>maxY || pt.y() < -maxY/2)
//        return true;
//    return false;
//}

Terrain::Terrain (QWidget *parent): QWidget(parent){
    width = 0;
    height = 0;
    isNoBorder = true;
}

Terrain::Terrain(const Game* g, int w,
                 int h, QWidget *parent):
            QWidget(parent), game(g){
    width = w;
    height = h;
    pic = QPixmap(width, height);
    isNoBorder = true;
}


