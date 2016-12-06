#include "circle.h"
#include <QColor>



QColor Circle::getColor() const
{
    return color;
}

void Circle::setColor(const QColor &value)
{
    color = value;
}

Circle::Circle(){
    radius = 0;
    radius_squared = 0;
    color = DEFAULT_COLOR;
}


Circle::Circle(float rad, QPointF center, QColor c){
    radius = rad;
    radius_squared = rad*rad;
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
