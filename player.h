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
    Vector2D direction,speed;
    int score,turn;
    bool isLiving;
    float angle, acceleration;
    CtrlKey ctrlKeys;

    /**
     * @brief update* : fonction to update player's component necessary
     * to moov a player
     */
    void updateSpeed();
    void updateRotate();
    void updatePosition();

public:
    Player();
    Player(QString pseudo, int rKey, int lKey);
    void moov();
    QPointF getPosition() const;
    void kill();
    void increaseScore();
    float getAngle() const;
    void drawItem(QPainter *painter)const;
    int getScore() const;
    bool getIsLiving() const;
    QString getPseudo() const;
    void setColor(QColor c);

    bool operator==(Player& p);
    bool operator!=(Player& p);
    virtual ~Player();

    /**
     * @brief isMyColor
     * @param c
     * @return true if c is the player color
     */
    bool isMyColor(QColor c);

    /**
     * @brief isNextTo
     * @param p
     * @return true if the position (or a p player's position) is next to him
     */
    bool isNextTo(Player* p);
    bool isNextTo(QPointF p);

    /**
     * @brief checkKey : Do modifications in function to the key event
     * @param event
     * @return
     */
    bool checkKey(QKeyEvent* event);

    /**
     * @brief getCollisionPoints
     * @return the 5 points arround the player head to detect collisions
     */
    QVector<QPointF> getCollisionPoints() const ;

    /**
     * @brief getRandPos
     * @return return a random beginning position for a player
     * to not to close to walls
     */
    static QPointF getRandPos();

    /**
     * @brief getRandColor
     * @return return a random color not to dark to be visible
     * on the black background
     */
    static QColor getRandColor();

    /**
     * @brief hasSameColor
     * @param c
     * @return true if the player has a color similar to c
     */
    bool hasSameColor(QColor c);

    /**
     * @brief makeBigger : increase player head radius to r
     * @param r
     */
    void makeBigger(float r);
    void makeSmaller(float r);

    /**
     * @brief accelerate : add value to acceleration
     * @param value
     */
    void accelerate(float value);

};

#endif // PLAYER_H
