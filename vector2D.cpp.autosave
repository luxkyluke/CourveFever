#include "vector2D.h"
#include <iostream>


Vector2D::Vector2D(QPointF p): QPointF(p.x(), p.y()){
}

Vector2D::Vector2D(QPointF p1, QPointF p2)
    : QPointF(p1.x() - p2.x(), p1.y() - p2.y()){

}

Vector2D::Vector2D(float x, float y): QPointF(x, y){
}

Vector2D::Vector2D(): QPointF(0., 0.){

}

void Vector2D::sub(Vector2D &v){
    setX(x()-v.x());
    setY(y()-v.y());
}

void Vector2D::multi(float a){
    setX(x()*a);
    setY(y()*a);
}

void Vector2D::div(float a){
    setX(x()/a);
    setY(y()/a);
}

float Vector2D::sqrNorm(){
    return this->dotProduct(*this);
}

float Vector2D::dotProduct(Vector2D &v) const{
    return x() * v.x() + y() * v.y();
}

void Vector2D::operator=(const Vector2D &v){
    setX(v.x());
    setY(v.y());
}

Vector2D Vector2D::operator+=(const Vector2D &v){
    return Vector2D(dynamic_cast<QPointF*>(this)->operator +=(v));
}

Vector2D Vector2D::operator+(const Vector2D &v1){
    return Vector2D(this->x()+v1.x(), this->y()+v1.y());
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v){
    os << "x :" << v.x() << " y :" << v.y() << std::endl;
    return os;
}

QPointF operator+(QPointF &p, const Vector2D &v){
    return QPointF(p.x()+v.x(), p.y()+p.y());
}

Vector2D operator*(Vector2D &v, float a){
    Vector2D ret;
    ret = v;
    ret.multi(a);
    return ret;
}

