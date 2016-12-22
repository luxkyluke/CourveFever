#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QKeyEvent>
#include <QVector>
#include <QString>
#include<QColor>

#include "circle.h"
#include "vector2D.h"
#include "ctrlKey.h"


const static int NB_KEYS = 2;

class Player : public Circle{

private:
    QString pseudo;
    Vector2D direction,
           speed;
    int score,
        turn;
    bool isLiving;
    float angle, acceleration;
    CtrlKey ctrlKeys;

    void updateSpeed();
    void updateRotate();
    void updatePosition();
    //void updateHeadPosition();


public:
    Player();
    Player(QString pseudo, int rKey, int lKey);
    void moov();
    QPointF getPosition() const;
    bool isMyColor(QColor c);
    bool getRun() const;
    bool isACrtlKey(int key);
    void kill();
    bool isNextTo(Player* p);
    bool isNextTo(QPointF p);
    bool checkKey(QKeyEvent* event);
    QVector<QPointF> getCollisionPoints() const ;
    void increaseScore();
    float getAngle() const;
    void drawItem(QPainter *painter)const;
    Vector2D getDirection() const;
    int getScore() const;
    bool getIsLiving() const;
    QString getPseudo() const;
    static QPointF getRandPos();
    static QColor getRandColor();
    void setColor(QColor c);
    bool hasSameColor(QColor c);
    bool operator==(Player& p);
    bool operator!=(Player& p);
    void makeBigger(float r);
    void makeSmaller(float r);
    void reset();
    virtual ~Player();
    void accelerate(float value);
    void resetSpeed();
};

#endif // PLAYER_H
