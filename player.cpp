#include "player.h"
#include "terrain.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>


using namespace std;

const static float DEFAULT_ACCELERATION = 1.5;
//a changer pour le multijoueur ! Aléatoir autour du centre
const static QPointF DEFAULT_POSITION = QPointF(0., 0.);
const static float DEFAULT_RADIUS = 5.;
const static Vector2D DEFAULT_DIR = Vector2D(0., 1.);
const static Vector2D DEFAULT_SPEED = Vector2D(0., 0.);
const static int RANDOM_POS_RANGE = 200;
const static float DEFAULT_ANGLE = 3;
const static int COLLISION_DISTANCE = 6;

Player::Player(): direction(DEFAULT_DIR),
            Circle(DEFAULT_RADIUS, DEFAULT_POSITION),
            ctrlKeys(CtrlKey()){
    score =0;
    turn = 0;
    angle = 0.;
    srand(time(NULL));
    int r = rand() %185 + 70;
    int g = rand() %185 + 70;
    int b = rand() %185 + 70;
    setColor(QColor(r, g, b, 255));
    isLiving = true;
}

int gettimeofday(struct timeval* p, void* tz) {
    ULARGE_INTEGER ul; // As specified on MSDN.
    FILETIME ft;

    // Returns a 64-bit value representing the number of
    // 100-nanosecond intervals since January 1, 1601 (UTC).
    GetSystemTimeAsFileTime(&ft);

    // Fill ULARGE_INTEGER low and high parts.
    ul.LowPart = ft.dwLowDateTime;
    ul.HighPart = ft.dwHighDateTime;
    // Convert to microseconds.
    ul.QuadPart /= 10ULL;
    // Remove Windows to UNIX Epoch delta.
    ul.QuadPart -= 11644473600000000ULL;
    // Modulo to retrieve the microseconds.
    p->tv_usec = (long) (ul.QuadPart % 1000000LL);
    // Divide to retrieve the seconds.
    p->tv_sec = (long) (ul.QuadPart / 1000000LL);

    return 0;
}

QPointF Player::getRandPos(){
    QPointF randPos;
    float randX = rand() %RANDOM_POS_RANGE;
    float randY = rand() %RANDOM_POS_RANGE;
    randPos = QPointF(randX, 0);
    return randPos;
}

Player::Player(QString _pseudo, int rKey, int lKey): direction(DEFAULT_DIR),
            Circle(DEFAULT_RADIUS, Player::getRandPos()),
            ctrlKeys(CtrlKey(rKey, lKey)),
            speed(DEFAULT_SPEED){
    score =0;
    angle = 0.;
    turn = 0;
    //srand(time(NULL));
    int r = rand() %185 + 70;
    int g = rand() %185 + 70;
    int b = rand() %185 + 70;

    setColor(QColor(r, g, b, 255));
    isLiving = true;
    pseudo = _pseudo;
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

    pts.append(pos + getPointbyAngle(angle)*COLLISION_DISTANCE);
    pts.append(pos + getPointbyAngle(angle+45)*COLLISION_DISTANCE);
    pts.append(pos + getPointbyAngle(angle+90)*COLLISION_DISTANCE);
    pts.append(pos + getPointbyAngle(angle-45)*COLLISION_DISTANCE);
    pts.append(pos + getPointbyAngle(angle-90)*COLLISION_DISTANCE);


    return pts;
}

void Player::increaseScore(){
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
    speed = direction * DEFAULT_ACCELERATION;
}

void Player::updatePosition(){
    position += speed;
}
