#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QKeyEvent>
#include <QVector>

#include "circle.h"
#include "vector2D.h"
#include "matrix.h"
#include "ctrlKey.h"


static int ITERATEUR_ID = 0;
const static int NB_KEYS = 2;

class Player : public Circle{

private:
    //Circle head;
    Vector2D direction,
           speed;
    int score,
        turn;
    bool isLiving;
    float angle;
    CtrlKey ctrlKeys;

    void updateSpeed();
    void updateRotate();
    void updatePosition();
    //void updateHeadPosition();

public:
    Player();
    Player(int rKey, int lKey);
    void moov();
    QPointF getPosition() const;
    bool isMyColor(QColor c);
    bool getRun() const;
    bool isACrtlKey(int key);
    void kill();
    bool checkKey(QKeyEvent* event);
    QVector<QPointF> getCollisionPoints() const ;
    void increaseScore();
    float getAngle() const;
    void drawItem(QPainter *painter)const;
    Vector2D getDirection() const;
    int getScore() const;
    bool getIsLiving() const;
};

#endif // PLAYER_H
