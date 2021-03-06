#ifndef GAMEITEM_H
#define GAMEITEM_H
#include <qpainter.h>
#include <QGLWidget>
#include <QPointF>

/**
 * @brief The GameItem class : Abstract class which represente
 * every element of the game
 */
class GameItem{
protected:
    QPointF position;
public:
    virtual void drawItem(QPainter *painter) const = 0;
    QPointF getPosition() const;
    void setPosition(const QPointF &value);
};

#endif // GAMEITEM_H
