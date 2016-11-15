#include "vector2D.h"

QPointF operator+(QPointF &p, Vector2D &v){
    return QPointF(p.x()+v.x(), p.y()+p.y());
}

Vector2D::Vector2D(QPointF p): QPointF(p.x(), p.y()){
}

Vector2D::Vector2D(float x, float y): QPointF(x, y){
}

Vector2D::Vector2D(): QPointF(0., 0.){

}

void Vector2D::add(Vector2D &v){
    setX(x()+v.x());
    setY(y()+v.y());
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

float Vector2D::norm(){
    return 0.;//sqrt(SqrNorm(v));
}

float Vector2D::normalize(){
    return 0.;//QPoint();
}

float Vector2D::dotProduct(Vector2D &v) const{
    return x() * v.x() + y() * v.y();
}
