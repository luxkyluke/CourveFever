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
    const Game* game;       // saved to draw it
    QPixmap pic;            //the "black-board" where everything is drawn
    int width, height;
    bool isNoBorder;        //to draw borders only one time

    /**
     * @brief drawBorders : to draw border (white line arround the terrain
     * to detect collisions)
     * @param painter
     */
    void drawBorders(QPainter& painter);

    /**
     * @brief isBlack : check if pixel is black in position pt
     * @param pt
     * @param c
     * @return
     */
    bool isBlack(QPointF pt, QColor* c);

public:
    Terrain(QWidget *parent =0);
    Terrain(const Game* g, int w, int h, QWidget *parent =0);
    int getWidth() const;
    int getHeight() const;
    QPixmap getPic() const;

    /**
     * @brief paintEvent : event called to refresh the terrain
     * @param pe
     */
    void paintEvent(QPaintEvent *pe);
    void paint();

    /**
     * @brief isInCollision : get player's collisions position
     * and check every pixels in those positions to know is they
     * are black. If they don't, it mean, there is a collision, and so the
     * color pointer will be fill with the unusual color met.
     * @param p
     * @param c
     * @return
     */
    bool isInCollision(Player* p, QColor *c);

    /**
     * @brief isBordersColor
     * @param c
     * @return true is the c color is the same as borders color
     */
    bool isBordersColor(QColor c);

    /**
     * @brief clear : reset the pic
     */
    void clear();

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

};



#endif // TERRAIN_H
