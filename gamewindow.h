#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include "playerinfowidget.h"
#include "player.h"


//class Game;
class Terrain;
class Game;

class GameWindow : public QMainWindow{
    Q_OBJECT
    Terrain* canva;
    QLabel *terrainLabel, *titre;
    QVector<PlayerInfoWidget*> playersInfos;
    QVector<Player*> *players;
    QWidget* scoreWidget;

public:
    //explicit MainWindow(QWidget *parent = 0);
    explicit GameWindow(const int w, const int h,
            QVector<Player*>* _scores, QWidget *parent = 0);
    void keyPressEvent();
    void keyReleaseEvent();
    void paintEvent(QPaintEvent *e);
    void setCanvas(Terrain* t);
    void updateScores();
    //void addPlayerToScoreTab(const Player* p);
    virtual ~GameWindow();


    //Canvas *getRenderer() const;
};

#endif // MAINWINDOW_H
