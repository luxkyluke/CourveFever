#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "gameitem.h"

/**
 * @brief The Vector2D class : Made to manage the physical gestures
 */
class Vector2D : public QPointF{

public:
    Vector2D(QPointF p);
    Vector2D(QPointF p, QPointF p2);
    Vector2D();
    Vector2D(float x, float y);
    void sub(Vector2D & v);
    void multi(float a);
    void div(float a);

    float sqrNorm();
    float dotProduct(Vector2D &v) const;
    void operator=(const Vector2D &v);
    Vector2D operator+=(const Vector2D &v);
    Vector2D operator+(const Vector2D &v1);
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v);
Vector2D operator*(Vector2D &v, float a);
QPointF operator+(QPointF &p, const Vector2D &v);

#endif // VECTOR2D_H
