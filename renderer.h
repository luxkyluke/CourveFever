#ifndef RENDERER_H
#define RENDERER_H


#include <QWidget>
#include <QGLWidget>
#include <QtOpenGL>
class Game;

class Renderer : public QGLWidget
{
    Q_OBJECT
    Game *game;
public:

    explicit Renderer(Game* g, QWidget *parent = 0);
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintEvent(QPaintEvent * event);


signals:

public slots:

};

#endif // RENDERER_H
