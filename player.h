#ifndef PLAYER_H
#define PLAYER_H
#include "gameitem.h"
#include "circle.h"
#include "vector2D.h"
#include "matrix.h"

static int ITERATEUR_ID = 0;
class Player : public GameItem{

    Circle head;
    Vector2D direction,
           speed,
           acceleration;
    bool isRunning;
    int score,
        turn,
        id;
    float angle;
    void updatePosition();
    void updateRotate();

public:
    Player();
    void moov(Vector2D dir);

    bool getRun() const;
    void setRun(bool value);
    int getTurn() const;
    void setTurn(int value);

    float getAngle() const;
    void setAngle(float value);
};

#endif // PLAYER_H
