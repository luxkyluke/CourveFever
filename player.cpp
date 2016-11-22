#include "player.h"
#include <math.h>
#include <iostream>
using namespace std;

const static float DEFAULT_ACCELERATION = 1.5;
const static QPointF DEFAULT_POSITION = QPointF(0., 0.);
const static float DEFAULT_RADIUS = 10.;
const static Vector2D DEFAULT_DIR = Vector2D(0., 1.);
const static Vector2D DEFAULT_SPEED = Vector2D(0., 0.);
const static float DEFAULT_ANGLE = 3;

Player::Player(): direction(DEFAULT_DIR),
            Circle(DEFAULT_RADIUS, DEFAULT_POSITION),
            ctrlKeys(CtrlKey()){
    score =0;
    turn = 0;
    angle = 0.;
}

Player::Player(int rKey, int lKey): direction(DEFAULT_DIR),
            Circle(DEFAULT_RADIUS, DEFAULT_POSITION),
            ctrlKeys(CtrlKey(rKey, lKey)),
            speed(DEFAULT_SPEED){
    id = ITERATEUR_ID++;
    score =0;
    angle = 0.;
    turn = 0;
}

void Player::moov(){
    updateRotate();
    updateSpeed();
    updatePosition();
}

QPointF Player::getPosition(){
    return Circle::getPosition();
}

bool Player::getRun() const{
    return isRunning;
}

void Player::setRun(bool value){
    isRunning = value;
}

//int Player::getTurn() const{
//    return turn;
//}

//void Player::setTurn(int value){
//    turn = value;
//}

//bool Player::isACrtlKey(int key){
//    for(int i=0; i<sizeof(ctrl_keys); ++i){
//        if(ctrl_keys[i] == key)
//            return true;
//    }
//    return false;
//}

bool Player::checkKey(QKeyEvent* event){
    if(!ctrlKeys.isCtrlKey(event->key()))
        return false;
    if(event->type() == QKeyEvent::KeyPress){

        if(event->key() ==  ctrlKeys.getRightKey()){
           turn = 1;

        }else if(event->key() ==  ctrlKeys.getLeftKey()){
           turn = -1;
        }
    }
    else if(event->type() == QKeyEvent::KeyRelease){
         turn = 0;
    }
    return true;
}

float Player::getAngle() const{
    return angle;
}

void Player::setAngle(float value){
    angle = value;
}

void Player::drawItem(QPainter *painter, QGLWidget &window){
    Circle::drawItem(painter, window);
}


void Player::updateRotate(){
    if(turn != 0){
        angle -= float(turn*DEFAULT_ANGLE);
        qreal nx = qreal(-sin((M_PI * angle) / 180));
        qreal ny = qreal(cos((M_PI * angle) / 180));
        direction.setX(nx);
        direction.setY(ny);
    }
}

void Player::updateSpeed(){
    speed = direction * DEFAULT_ACCELERATION;
}

void Player::updatePosition(){
    position += speed;
}
