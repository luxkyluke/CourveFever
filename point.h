#ifndef POINT_H
#define POINT_H


class Point{
    float x, y;
public:
    Point();
    Point(const float _x, const float _y);

    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);


};

#endif // POINT_H
