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
    painter.setBrush(QColor::fromRgbF(1, 1, 1, 1));
    painter.drawEllipse(facePt, 2, 2);
    painter.setBrush(QColor::fromRgbF(1, 0, 0, 1));
    painter.drawEllipse(halfLeftPt, 2, 2);
    painter.drawEllipse(halfRightPt, 2, 2);

    painter.drawEllipse(rightPt, 2, 2);
    painter.drawEllipse(leftPt, 2, 2);
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

QPointF getPointbyAngle(float angle){
    qreal nx = qreal(-sin((M_PI * angle) / 180.));
    qreal ny = qreal(cos((M_PI * angle) / 180.));
    return QPointF(nx, ny);
}

bool Terrain::checkCollisions(Player* p){
    float currentAngle = p->getAngle();
    QPointF pos = p->getPosition();
    Vector2D dir = p->getDirection();
    float distance = 10;
    facePt = pos + getPointbyAngle(currentAngle)*distance;//*distance;//*distance);
    halfRightPt = pos + getPointbyAngle(currentAngle+45)*distance;
    rightPt = pos + getPointbyAngle(currentAngle+90)*distance;
    halfLeftPt = pos + getPointbyAngle(currentAngle-45)*distance;
    leftPt = pos + getPointbyAngle(currentAngle-90)*distance;

}

QPointF Terrain::getFacePt() const
{
    return facePt;
}

QPointF Terrain::getRightPt() const
{
    return rightPt;
}

QPointF Terrain::getLeftPt() const
{
    return leftPt;
}

Terrain::Terrain (QWidget *parent): QWidget(parent){
    width = 0;
    height = 0;
    facePt = QPoint(0, 0);
    rightPt=QPoint(0, 0);
    leftPt =QPoint(0, 0);
}

Terrain::Terrain(const Game* g, int w,
                 int h, QWidget *parent):
            QWidget(parent), game(g){
    width = w;
    height = h;
    pic = QPixmap(width, height);
    facePt =QPoint(0, 0);
    rightPt=QPoint(0, 0);
    leftPt =QPoint(0, 0);
}


