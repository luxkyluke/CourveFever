#ifndef TERRAIN_H
#define TERRAIN_H
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QWidget>
#include <QVector>
#include <QPoint>
#include "player.h"

class Game;


class Terrain : public QWidget{
private:
    //Matrix pixels;
    const Game* game;

    QPixmap pic;
    int width, height;
    bool isNoBorder;

    void drawBorders(QPainter& painter);
    bool isBlack(QPointF pt, QColor* c); //check if pixel is black in position pt

public:
    Terrain(QWidget *parent =0);
    Terrain(const Game* g, int w,
                     int h, QWidget *parent =0);
    int getWidth() const;
    int getHeight() const;
    void paintEvent(QPaintEvent *pe);

    QPixmap getPic() const;
    bool isInCollision(Player* p, QColor *c);
    bool isBordersColor(QColor c);


    //change coordinates x, y which have origin (0,0)
    //in the middle of the scene by coord (0,0) based
    //in left top of the img
    int getXImgCoord(const float x);
    int getYImgCoord(const float y);

    //change coordinates x, y which have origin (0,0)
    //in left top of the img by coord (0,0) based
    //in the middle of the scene
    static float getYLandmarkCoord(const int y, const int h);
    static float getXLandmarkCoord(const int x, const int w);

    static QPointF getCoordInLandmarkDim(QPoint &pt, const int &w, const int &h);
    QPoint getCoordInImgDim(QPointF& pt);
    void changeCoordInImgDim(const float x, const float y,
                          int *_x, int*_y);

};



#endif // TERRAIN_H
