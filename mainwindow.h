#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"
#include <QLabel>


class Game;

class MainWindow : public QMainWindow{

    Canvas* canva;
    QLabel* label;
    Game* game;

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(Game *g, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void repaintRenderer();
    void paintEvent(QPaintEvent *e);
    ~MainWindow();


    Canvas *getRenderer() const;
};

#endif // MAINWINDOW_H
