#include "circle.h"
#include <QColor>

static const QColor DEFAULT_COLOR(255, 255, 255, 255);

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

Circle::Circle(float rad, QPointF center){
    radius = rad;
    radius_squared = rad*rad;
    position = center;
    color = DEFAULT_COLOR;
}

QPointF Circle::getPosition() const{
    return GameItem::getPosition();
}

void Circle::drawItem(QPainter *painter) const{
    painter->setBrush(color);
    painter->drawEllipse(position, radius, radius);
}
