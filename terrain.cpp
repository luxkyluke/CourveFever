#include "terrain.h"
#include "game.h"
#include <iostream>
#include <QPoint>


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
    QPen pen( Qt::white );
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

int Terrain::getXImgCoord(const float x){
    return x +(width/2);
}

int Terrain::getYImgCoord(const float y){
     return -y + (height/2);
}

QPixmap Terrain::getPic() const{
    return pic;
}

bool Terrain::isBlack(QPointF pt){
    QImage pixels = pic.toImage();
    QPoint coordsInIMG = getCoordInImgDim(pt);
    return pixels.pixelColor(coordsInIMG) == QColor(0, 0, 0, 255);
}

bool Terrain::checkCollisions(Player* p){
    QVector<QPointF> pts = p->getCollisionPoints();
    foreach(QPointF pt, pts){
        if(!isBlack(pt)){
            std::cout <<"point "<<pt<<endl;
            std::cout<<"MORT"<<std::endl;
            return false;
        }
    }
    return true;
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


