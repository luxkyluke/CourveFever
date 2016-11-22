#ifndef GAMEITEM_H
#define GAMEITEM_H
#include <qpainter.h>
#include <QGLWidget>
#include <QPointF>


class GameItem{


protected:
    QPointF position;
public:
    virtual void drawItem(QPainter *painter, QGLWidget &window) = 0;
    QPointF getPosition() const;
    void setPosition(const QPointF &value);
};

#endif // GAMEITEM_H
