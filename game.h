#ifndef GAME_H
#define GAME_H
#include <QVector>
#include <QObject>
#include "terrain.h"
#include "player.h"

//#include "mainwindow.h"


class Game{

    QVector<Player> players;
    Terrain terrain;

public:
    Game();
    Game(const int w, const int h, Player &p);
    void addPlayer(Player &p);
    bool keyPressed(int key);
    void draw(QPainter &painter, QGLWidget &window);

};

#endif // GAME_H
