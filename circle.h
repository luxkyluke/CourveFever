#ifndef CIRCLE_H
#define CIRCLE_H
#include "gameitem.h"


class Circle : public GameItem{
    float radius;
    float radius_squared;
public:
    Circle();
    Circle(float rad, QPointF center);
    QPointF getPosition();
    void drawItem(QPainter *painter) const;
};

#endif // CIRCLE_H
