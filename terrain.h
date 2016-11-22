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
    QImage getPixels() const;
    void update(QGLWidget* renderer);
};

#endif // TERRAIN_H
