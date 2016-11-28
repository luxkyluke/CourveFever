#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "terrain.h"
#include "game.h"
#include <iostream>
#include <QVBoxLayout>

//Canvas *MainWindow::getRenderer() const
//{
//    return canva;
//}

//MainWindow::MainWindow(QWidget *parent):
//    QMainWindow(parent){

//}

MainWindow::MainWindow(const int w, const int h, QWidget *parent):QMainWindow(parent){
    this->resize(w, h);

    label = new QLabel("start", this);

    QVBoxLayout *vbl = new QVBoxLayout(this);

    vbl->addWidget(label);

    this->setCentralWidget(label);
}


void MainWindow::setCanvas(Terrain* t){
    canva = t;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
}

void MainWindow::keyReleaseEvent(QKeyEvent* event){
}

//void MainWindow::repaintRenderer(){
//    //canva->update();
//}

void MainWindow::paintEvent(QPaintEvent *e){
    canva->paintEvent(e);
    label->setPixmap(canva->getPic());
}

MainWindow::~MainWindow(){

}

