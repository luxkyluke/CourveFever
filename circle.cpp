#include "circle.h"
#include <QColor>

const static int COLOR_RANGE =50;

QColor Circle::getColor() const{
    return color;
}

void Circle::addRadius(float r){
    radius += r;
}

bool Circle::hasSameColor(QColor c){
    return (c.red() < color.red()+COLOR_RANGE
            && c.red() > color.red()-COLOR_RANGE
            && c.blue() < color.blue()+COLOR_RANGE
            && c.blue() > color.blue()-COLOR_RANGE
            && c.green() < color.green()+COLOR_RANGE
            && c.green() > color.green()-COLOR_RANGE);
}


void Circle::resetRadius(){
    radius = initialRadius;
}

float Circle::getRadius(){
    return radius;
}

void Circle::setColor(const QColor &value){
    color = value;
}

Circle::Circle(){
    radius = 0;
    initialRadius = 0;
    color = DEFAULT_COLOR;
}


Circle::Circle(float rad, QPointF center, QColor c){
    radius = rad;
    initialRadius = rad;
    position = center;
    color = c;
}

QPointF Circle::getPosition() const{
    return GameItem::getPosition();
}

void Circle::drawItem(QPainter *painter) const{
    painter->setBrush(color);
    painter->drawEllipse(position, radius, radius);
}
