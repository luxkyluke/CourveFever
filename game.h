#ifndef GAME_H
#define GAME_H
#include <QVector>
#include <QObject>
#include "terrain.h"
#include "player.h"

#include "mainwindow.h"


class Game : public QObject{
    Q_OBJECT
    QVector<Player*> players;
    Terrain terrain;
    MainWindow window;

    void updateScene();

public:
    Game(const int w, const int h, Player *p);
    void addPlayer(Player *p);
    bool keyEvent(QKeyEvent* event);
    void draw(QPainter *painter) const;
    int getWidth() const;
    int getHeight() const;
    bool eventFilter(QObject *object, QEvent *event);

public slots:
    void refresh();

};

#endif // GAME_H
