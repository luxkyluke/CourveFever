#ifndef GAMEITEM_H
#define GAMEITEM_H
#include "point.h"
#include <qpainter.h>
#include <QGLWidget>


class GameItem{


protected:
    Point position;
public:
    virtual void drawItem(QPainter &painter, QGLWidget &window) = 0;
    Point getPosition() const;
    void setPosition(const Point &value);
};

#endif // GAMEITEM_H
