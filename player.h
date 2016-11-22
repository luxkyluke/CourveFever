#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
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
    bool isRunning;
    int score,
        turn,
        id;

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
    QPointF getPosition();

    bool getRun() const;
    void setRun(bool value);
//    int getTurn() const;
//    void setTurn(int value);
    bool isACrtlKey(int key);
    bool checkKey(QKeyEvent* event);

    float getAngle() const;
    void setAngle(float value);

    void drawItem(QPainter *painter, QGLWidget &window);

};

#endif // PLAYER_H
