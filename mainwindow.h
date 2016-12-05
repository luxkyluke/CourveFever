#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>


//class Game;
class Terrain;
class Game;

class MainWindow : public QMainWindow{

    Terrain* canva;
    QLabel* label;
    //Game* game;

public:
    //explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(const int w, const int h, QWidget *parent = 0);
    void keyPressEvent();
    void keyReleaseEvent();
    //void repaintRenderer();
    void paintEvent(QPaintEvent *e);
    void setCanvas(Terrain* t);
    ~MainWindow();


    //Canvas *getRenderer() const;
};

#endif // MAINWINDOW_H
