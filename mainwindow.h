#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
class Game;

class MainWindow : public QMainWindow{

    QGLWidget* w;
    Game* game;

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(Game *g, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void repaintRenderer();

    ~MainWindow();


    QGLWidget *getRenderer() const;
};

#endif // MAINWINDOW_H
