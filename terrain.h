#ifndef TERRAIN_H
#define TERRAIN_H
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QGLWidget>

class Terrain
{
    //Matrix pixels;
    QImage pixels;
    int width, height;

public:
    Terrain();
    Terrain(int nb_row, int nb_col);
    int getWidth() const;
    int getHeight() const;
    QImage& getPixels() ;
    QColor getPixel(int x, int y);
    QColor getPixel(QPointF& pt);
    void update(QGLWidget* renderer);

    void changeCoordInImgDim(const float x, const float y,
                          int *_x, int*_y);
    QPoint getCoordInImgDim(QPointF& pt);

    //change coordinates x, y which have origin (0,0)
    //in the middle of the scene by coord (0,0) based
    //in left top of the img
    int getXImgCoord(const float x);
    int getYImgCoord(const float y);
};



#endif // TERRAIN_H
