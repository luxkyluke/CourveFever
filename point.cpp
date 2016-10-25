#include "point.h"

float Point::getX() const{
    return x;
}

void Point::setX(float value){
    x = value;
}

float Point::getY() const{
    return y;
}

void Point::setY(float value){
    y = value;
}

Point::Point(){
    x=0.;
    y=0.;
}

Point::Point(const float _x, const float _y){
    x = _x;
    y = _y;
}
