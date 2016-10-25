#include "circle.h"
#include <QColor>

Circle::Circle(){
    radius = 0;
    radius_squared = 0;
}

Circle::Circle(float rad, Point center){
    radius = rad;
    radius_squared = rad*rad;
    position = center;
}

void Circle::drawItem(QPainter &painter, QGLWidget &window){
    painter.begin(&window);
    painter.setBrush(QColor::fromRgbF(0, 1, 0, 1));
    painter.drawEllipse(position, radius, radius);
    painter.end();
}
