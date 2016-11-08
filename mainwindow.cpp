#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderer.h"
#include "circle.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    this->resize(800, 800);

    w = new Renderer(this);

    this->setCentralWidget(w);
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter p;
    Circle c(5., QPoint(0., 0.));
    c.drawItem(p, *w);
}

MainWindow::~MainWindow(){

}
