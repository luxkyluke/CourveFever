#ifndef CANVAS_H
#define CANVAS_H


#include <QWidget>
#include <QtOpenGL>
#include <QPixmap>

class Game;

class Canvas : public QWidget{
    Q_OBJECT
    QPixmap pic;
    const Game* game;
public:
    explicit Canvas(const Game* g, QWidget *parent = 0);
    void paintEvent(QPaintEvent *pe);
    QPixmap getPic() const;
};

#endif // CANVAS_H
