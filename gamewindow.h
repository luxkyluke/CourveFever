#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPushButton>

#include "playerinfowidget.h"
#include "player.h"


//class Game;
class Terrain;
class Game;

class GameWindow : public QMainWindow{
    Q_OBJECT
    Terrain* terrainCanva;
    QLabel *terrainLabel, *title, *remainingTime;
    QVector<PlayerInfoWidget*> playersInfos;
    QVector<Player*> *players;
    QWidget* scoreWidget, *preGameOverlay;
    QWidget *terrainOverlay;

public:
    explicit GameWindow(const int w, const int h,
            QVector<Player*>* _scores, Game *game, QWidget *parent = 0);
    void keyPressEvent();
    void keyReleaseEvent();
    void paintEvent(QPaintEvent *e);
    void setCanvas(Terrain* t);
    void updateScores();
    virtual ~GameWindow();
    void displayRemainingTime(int time);

    void theEnd(int id);

};

#endif // MAINWINDOW_H
