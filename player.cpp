#include "player.h"
#include <math.h>



Player::Player(): direction(1.,0.){
    id = ITERATEUR_ID++;
    score =0;
    turn =0;
    head = Circle(2., QPointF(0., 0.));
    angle = 0.;
}

void moov(Vector2D dir){

}

bool Player::getRun() const{
    return isRunning;
}

void Player::setRun(bool value){
    isRunning = value;
}

int Player::getTurn() const{
    return turn;
}

void Player::setTurn(int value){
    turn = value;
}

float Player::getAngle() const{
    return angle;
}

void Player::setAngle(float value){
    angle = value;
}

void Player::updatePosition(){
    position = position + speed;
}

void Player::updateRotate(){
    if(turn != 0){
        angle -= turn * 2;
        direction.setX(qreal(-sin((M_PI * angle) / 180)));
        direction.setY(cos((M_PI * angle) / 180));
    }
}
