#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "gameitem.h"

class Vector2D : public QPointF{

public:
    Vector2D(QPointF p);
    Vector2D();
    Vector2D(float x, float y);
    void add(Vector2D & v);
    void sub(Vector2D & v);
    void multi(float a);
    void div(float a);

    float sqrNorm();
    float norm();
    float normalize();
    float dotProduct(Vector2D &v) const;

private:

};

QPointF operator+(QPointF &p, Vector2D &v);

#endif // VECTOR2D_H
