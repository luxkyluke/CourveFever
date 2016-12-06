#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>


//class Game;
class Terrain;
class Game;

class GameWindow : public QMainWindow{

    Terrain* canva;
    QLabel *terrainLabel, *titre;
    std::list<QLabel> scores;
    QWidget* scoreWidget;

public:
    //explicit MainWindow(QWidget *parent = 0);
    explicit GameWindow(const int w, const int h, QWidget *parent = 0);
    void keyPressEvent();
    void keyReleaseEvent();
    //void repaintRenderer();
    void paintEvent(QPaintEvent *e);
    void setCanvas(Terrain* t);
    ~GameWindow();


    //Canvas *getRenderer() const;
};

#endif // MAINWINDOW_H
