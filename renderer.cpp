#include "renderer.h"
#include <qpainter.h>
#include "circle.h"

Renderer::Renderer(QWidget *parent) : QGLWidget(parent){

}

void Renderer::initializeGL()
{
    // Set up the rendering context, define display lists etc.:

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Renderer::resizeGL(int w, int h){
    // setup viewport, projection etc.:
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Renderer::paintEvent(QPaintEvent * event){
    QPainter painter;
    Circle c(5., QPoint(0., 0.));
    c.drawItem(painter, *this);

}
