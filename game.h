#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "terrain.h"
#include "player.h"

#include "mainwindow.h"


class Game : public QObject{
private:
    Q_OBJECT
    QVector<Player*> players;
    Terrain terrain;
    int nbLivingPlayers;

    void updateScene();
    Player& getPlayer(QColor c);
    void checkCollision();

public:
    Game(const int w, const int h, Player *p);
    void addPlayer(Player *p);
    bool keyEvent(QKeyEvent* event);
    void draw(QPainter *painter) const;
    int getWidth() const;
    int getHeight() const;
    bool eventFilter(QObject *object, QEvent *event);


    Terrain* getTerrain();

public slots:
    void refresh();

};

#endif // GAME_H
