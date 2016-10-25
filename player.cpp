#include "player.h"

Player::Player(){
    id = ITERATEUR_ID++;
    score =0;
    turn =0;
    head = Circle(0., 0.);
    direction = Vector2D(1.,0.);
    speed = Vector2D(0., 0.);
    acceleration = Vector2D(0., 0.);
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

bool Player::getTourn() const{
    return isTurning;
}

void Player::setTourn(bool value){
    isTurning = value;
}

float Player::getAngle() const{
    return angle;
}

void Player::setAngle(float value){
    angle = value;
}

void Player::updatePosition(){
    position.add(speed);
}

void Player::updateRotate(){
    if(turn != 0){
        angle -= turn * 2;
        direction->setX(-sin((PI * angle) / 180));
        direction->setY(cos((PI * angle) / 180));
    }
}
