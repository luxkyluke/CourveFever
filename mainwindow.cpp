#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "game.h"
#include <iostream>

Canvas *MainWindow::getRenderer() const
{
    return canva;
}

//MainWindow::MainWindow(QWidget *parent):
//    QMainWindow(parent){

//}

MainWindow::MainWindow(const Game *g, QWidget *parent):
        QMainWindow(parent){
    this->resize(g->getWidth(), g->getHeight());

    label = new QLabel("start", this);

    canva= new Canvas(g, this);
    QVBoxLayout *vbl = new QVBoxLayout(this);

    vbl->addWidget(label);

    this->setCentralWidget(label);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
}

void MainWindow::keyReleaseEvent(QKeyEvent* event){
}

void MainWindow::repaintRenderer(){
    //canva->update();
}

void MainWindow::paintEvent(QPaintEvent *e){
    canva->paintEvent(e);
    label->setPixmap(canva->getPic());
}

MainWindow::~MainWindow(){

}

