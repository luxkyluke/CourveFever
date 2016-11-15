#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include "game.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
    QGLWidget* w;
    Game game;

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    ~MainWindow();

public slots:
    void refresh();
};

#endif // MAINWINDOW_H
