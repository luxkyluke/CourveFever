#ifndef CANVAS_H
#define CANVAS_H


#include <QWidget>
#include <QtOpenGL>
#include <QPixmap>


class Game;

class Canvas : public QWidget{
    Q_OBJECT
    Game *game;
    QPixmap pic;
public:
    explicit Canvas(Game* g, QWidget *parent = 0);
    void paintEvent(QPaintEvent *pe);
    QPixmap getPic() const;
};

#endif // CANVAS_H
