#ifndef PLAYER_H
#define PLAYER_H
#include "gameitem.h"
#include "circle.h"
#include "vector2D.h"

static const int ITERATEUR_ID = 0;
class Player : public GameItem{

    Circle head;
    Vector2D direction,
           speed,
           acceleration;
    bool isRunning;
    int score,
        turn,
        id;

    void updatePosition();

public:
    Player();
    void moov(Vector2D dir);

    bool getRun() const;
    void setRun(bool value);
    bool getTourn() const;
    void setTourn(bool value);

};

#endif // PLAYER_H
