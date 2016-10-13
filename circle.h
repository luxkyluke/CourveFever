#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    float radius;
    float radius_squared;
    Point center;
public:
    Circle();
    Circle(float rad, Point center);
};

#endif // CIRCLE_H
