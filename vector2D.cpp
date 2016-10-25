#include "vector2D.h"

float Vector2D::getX() const{
    return x;
}

float Vector2D::getY() const{
    return y;
}

void Vector2D::setX(float value){
    x = value;
}

void Vector2D::setY(float value){
    y = value;
}

void Vector2D::add(Vector2D v){
    x += v.getX();
    y += v.getY();
}

void Vector2D::sub(Vector2D v){
    x -= v.getX();
    y -= v.getY();
}

void Vector2D::multi(float a){
    x*=a;
    y*=a;
}

void Vector2D::div(float a){
    x/=a;
    y/=a;
}

float Vector2D::sqrNorm(){
    return this->dotProduct(this);
}

float Vector2D::norm(){
    return sqrt(SqrNorm(v));
}

float Vector2D::normalize(){
    return 0.;
}

float Vector2D::dotProduct(Vetor2D v) const{
    return x * v.getX() + y * v.getY();
}
