#ifndef CIRCLE_H
#define CIRCLE_H
#include "gameitem.h"


class Circle : public GameItem{
    float radius;
    float radius_squared;
    QColor color;

public:
    Circle();
    Circle(float rad, QPointF center);
    QPointF getPosition() const;
    void drawItem(QPainter *painter) const;
    QColor getColor() const;

protected:
    void setColor(const QColor &value);
};

#endif // CIRCLE_H
