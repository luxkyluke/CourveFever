#ifndef TERRAIN_H
#define TERRAIN_H
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QWidget>
#include <QVector>
#include "player.h"

class Game;


class Terrain : public QWidget{
private:
    //Matrix pixels;
    const Game* game;

    QPixmap pic;
    int width, height;
    bool isNoBorder;

    //bool isWall(QPointF pt);
    void drawBorders(QPainter& painter);
    bool isBlack(QPointF pt, QColor* c); //check if pixel is black in position pt

public:
    Terrain(QWidget *parent =0);
    Terrain(const Game* g, int w,
                     int h, QWidget *parent =0);
    int getWidth() const;
    int getHeight() const;
//    QImage& getPixels();
//    QColor getPixel(int x, int y);
//    QColor getPixel(QPointF& pt);
    //void update(QGLWidget* renderer);
    void paintEvent(QPaintEvent *pe);

    void changeCoordInImgDim(const float x, const float y,
                          int *_x, int*_y);
    QPoint getCoordInImgDim(QPointF& pt);
    QPixmap getPic() const;
    bool isInCollision(Player* p, QColor *c);
    bool isBordersColor(QColor c);

    //change coordinates x, y which have origin (0,0)
    //in the middle of the scene by coord (0,0) based
    //in left top of the img
    int getXImgCoord(const float x);
    int getYImgCoord(const float y);
};



#endif // TERRAIN_H
