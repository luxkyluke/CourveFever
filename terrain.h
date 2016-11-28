#ifndef TERRAIN_H
#define TERRAIN_H
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QWidget>

class Game;

class Terrain : public QWidget{
    //Matrix pixels;
    const Game* game;
    QImage pixels;
    QPixmap pic;
    int width, height;

public:
    Terrain(QWidget *parent =0);
    Terrain(const Game* g, int w,
                     int h, QWidget *parent =0);
    int getWidth() const;
    int getHeight() const;
    QImage& getPixels();
    QColor getPixel(int x, int y);
    QColor getPixel(QPointF& pt);
    //void update(QGLWidget* renderer);
    void paintEvent(QPaintEvent *pe);

    void changeCoordInImgDim(const float x, const float y,
                          int *_x, int*_y);
    QPoint getCoordInImgDim(QPointF& pt);

    QPixmap getPic() const;

    //change coordinates x, y which have origin (0,0)
    //in the middle of the scene by coord (0,0) based
    //in left top of the img
    int getXImgCoord(const float x);
    int getYImgCoord(const float y);

};



#endif // TERRAIN_H
