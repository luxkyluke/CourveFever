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

void Vector2D::add(Vector2D &v){
    float testx = this->x();
    float testy = this->y();
    float vx = v.x();
    float vy = v.y();
    float nx = testx + vx;
    float ny = testy + vy;
    this->setX(nx);
    this->setY(ny);
    std::cout<<nx<<"x = "<<testx << " + "<< vx<<std::endl;
    std::cout<<ny<<"y = "<<testy << " + "<< vy<<std::endl;
    std::cout<<"add = "<<*this<<std::endl;
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
    //   v.multi(a);
    ret = v;
    ret.multi(a);
    return ret;
}

QPointF getPointPlusAngle(QPointF dir, float angle){
    qreal nx = qreal(-sin((M_PI * angle) / 180));
    qreal ny = qreal(cos((M_PI * angle) / 180));
    return dir + QPointF(nx, ny);
}

