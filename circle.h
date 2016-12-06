#ifndef CIRCLE_H
#define CIRCLE_H
#include "gameitem.h"

static const QColor DEFAULT_COLOR(255, 255, 255, 255);

class Circle : public GameItem{
    float radius;
    float radius_squared;
    QColor color;

public:
    Circle();
    Circle(float rad, QPointF center, QColor c =DEFAULT_COLOR);
    QPointF getPosition() const;
    void drawItem(QPainter *painter) const;
    QColor getColor() const;

protected:
    void setColor(const QColor &value);
};

#endif // CIRCLE_H
