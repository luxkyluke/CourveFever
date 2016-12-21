#ifndef CIRCLE_H
#define CIRCLE_H
#include "gameitem.h"

static const QColor DEFAULT_COLOR(255, 255, 255, 255);

class Circle : public GameItem{
protected:
    float radius;
    float initialRadius;
    QColor color;

public:
    Circle();
    Circle(float rad, QPointF center, QColor c =DEFAULT_COLOR);
    QPointF getPosition() const;
    void drawItem(QPainter *painter) const;
    QColor getColor() const;
    void addRadius(float r);
    bool hasSameColor(QColor c);
    void resetRadius();

protected:
    void setColor(const QColor &value);
};

#endif // CIRCLE_H
