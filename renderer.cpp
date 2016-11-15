#include "renderer.h"
#include <qpainter.h>
#include "circle.h"
#include "game.h"

Renderer::Renderer(Game &g, QWidget *parent) :
    QGLWidget(parent), game(g){

}

void Renderer::initializeGL(){
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
    QPainter painter(this);
    painter.translate(width()/2, height()/2);
    painter.scale(1, -1);
//    painter.drawLine(QPointF(-500., 0.), QPointF(500., 0.)) ;
//    painter.drawLine(QPointF(0., -500.), QPointF(0., 500.));
//    Circle c(5., QPointF(-100., -200.));
//    c.drawItem(painter, *this);
    game.draw(painter, *this);
}
