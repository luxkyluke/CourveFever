#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "gameitem.h"
#include <QPointF>

class Vector2D : public Point{

public:

    void add(Vector2D v);
    void sub(Vector2D v);
    void multi(float a);
    void div(float a);

    float sqrNorm();
    float norm();
    float normalize();
    float dotProduct(Vetor2D v) const;

    float getX() const;
    float getY() const;
    void setX(float value);
    void setY(float value);
};

#endif // VECTOR2D_H
