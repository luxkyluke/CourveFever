#include "player.h"
#include "terrain.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>


using namespace std;

const static float DEFAULT_ACCELERATION = 1.5;
const static QPointF DEFAULT_POSITION = QPointF(0., 0.);
const static float DEFAULT_RADIUS = 5.;
const static Vector2D DEFAULT_DIR = Vector2D(0., 1.);
const static Vector2D DEFAULT_SPEED = Vector2D(0., 0.);
const static int RANDOM_POS_RANGE = 200;
const static float DEFAULT_ANGLE = 3;
const static int MIN_DISTANCE_BTW_PLAYERS = 15;

Player::Player(): Circle(DEFAULT_RADIUS, DEFAULT_POSITION),
            ctrlKeys(CtrlKey()){
    score =0;
    turn = 0;
    angle = 0.;
    speed = DEFAULT_SPEED;
    direction = DEFAULT_DIR;
    acceleration = 0.;
    setColor(QColor(255, 255, 0, 255));
    isLiving = true;
}



Player::Player(QString _pseudo, int rKey, int lKey): direction(DEFAULT_DIR),
            Circle(DEFAULT_RADIUS, DEFAULT_POSITION),
            ctrlKeys(CtrlKey(rKey, lKey)),
            speed(DEFAULT_SPEED){
    score =0;
    angle = 0.;
    turn = 0;
    setColor(Player::getRandColor());
    isLiving = true;
    acceleration = DEFAULT_ACCELERATION;
    pseudo = _pseudo;
}

QColor Player::getRandColor(){
    int r = rand() %185 + 70;
    int g = rand() %185 + 70;
    int b = rand() %185 + 70;
    return(QColor(r, g, b, 255));
}

QPointF Player::getRandPos(){
    QPointF randPos;
    float randX = rand() %RANDOM_POS_RANGE*2 - RANDOM_POS_RANGE;
    float randY = rand() %RANDOM_POS_RANGE*1.5 - RANDOM_POS_RANGE;
    randPos = QPointF(randX, randY);
    return randPos;
}

void Player::setColor(QColor c){
    Circle::setColor(c);
}

bool Player::hasSameColor(QColor c){
    return Circle::hasSameColor(c);
}

bool Player::operator==(Player &p){
    return pseudo == p.pseudo
        && direction == p.direction
        && speed == p.speed
        && score == p.score
        && turn == p.turn
        && isLiving == p.isLiving
        && angle == p.angle
        && ctrlKeys == p.ctrlKeys;
}

bool Player::operator!=(Player &p){
    return !this->operator==(p);
}

void Player::makeBigger(float r){
    Circle::addRadius(r);
}

void Player::makeSmaller(float r){
    makeBigger(-r);
}

void Player::reset(){
    position = Player::getRandPos();
    isLiving = true;
    direction = DEFAULT_DIR;
    score =0;
    turn = 0;
    angle = 0.;
}

Player::~Player(){

}

void Player::accelerate(float value){
    acceleration+=value;
}

void Player::resetSpeed(){
    acceleration = DEFAULT_ACCELERATION;
}


void Player::moov(){
    if(isLiving){
        updateRotate();
        updateSpeed();
        updatePosition();
    }
}

QPointF Player::getPosition() const{
    return Circle::getPosition();
}

bool Player::isMyColor(QColor c){
    return c == Circle::getColor();
}

void Player::kill(){
    isLiving = false;
}

bool Player::isNextTo(Player *p){
    if(p->position == this->position)
        return true;
    return (isNextTo(p->position));
}

bool Player::isNextTo(QPointF pos){
    if(pos == this->position)
        return true;
    return ((pos.x() < this->position.x()+MIN_DISTANCE_BTW_PLAYERS
            && pos.x() > this->position.x()-MIN_DISTANCE_BTW_PLAYERS)
             || (pos.y() < this->position.y()+MIN_DISTANCE_BTW_PLAYERS*4
                 && pos.y() > this->position.y()-MIN_DISTANCE_BTW_PLAYERS));
}

bool Player::checkKey(QKeyEvent* event){
    if(!isLiving)
        return false;
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

QPointF getPointbyAngle(const float angle){
    qreal nx = qreal(-sin((M_PI * angle) / 180.));
    qreal ny = qreal(cos((M_PI * angle) / 180.));
    return QPointF(nx, ny);
}

QVector<QPointF> Player::getCollisionPoints() const{
    const Vector2D pos = this->getPosition();
    const float angle = this->getAngle();
    QVector<QPointF> pts;
    pts.append(pos + getPointbyAngle(angle)*(radius+1));
    pts.append(pos + getPointbyAngle(angle+45)*(radius+1));
    pts.append(pos + getPointbyAngle(angle+90)*(radius+1));
    pts.append(pos + getPointbyAngle(angle-45)*(radius+1));
    pts.append(pos + getPointbyAngle(angle-90)*(radius+1));
    return pts;
}

void Player::increaseScore(){
    if(!isLiving)
        return;
    score++;
}

float Player::getAngle() const{
    return angle;
}

void Player::drawItem(QPainter *painter)const{
    Circle::drawItem(painter);
    painter->setBrush(QColor::fromRgbF(1, 0, 0, 1));
    QVector<QPointF> points = this->getCollisionPoints();
//    foreach(QPointF pt, points){
//        painter->drawEllipse(pt, 2, 2);
//    }
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

Vector2D Player::getDirection() const{
    return direction;
}

int Player::getScore() const{
    return score;
}

bool Player::getIsLiving() const{
    return isLiving;
}

QString Player::getPseudo() const
{
    return pseudo;
}

void Player::updateSpeed(){
    speed = direction * acceleration;
}

void Player::updatePosition(){
    position += speed;
}
